/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2018
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

#pragma once

namespace tracktion_engine
{

namespace
{
    static Plugin::Array findAllPlugins (tracktion_graph::Node& node)
    {
        Plugin::Array plugins, insideRacks;

        for (auto n : getNodes (node, VertexOrdering::preordering))
            if (auto pluginNode = dynamic_cast<PluginNode*> (n))
                plugins.add (&pluginNode->getPlugin());

        for (auto plugin : plugins)
            if (auto rack = dynamic_cast<RackInstance*> (plugin))
                if (auto type = rack->type)
                    for (auto p : type->getPlugins())
                        insideRacks.addIfNotAlreadyThere (p);

        plugins.addArray (insideRacks);
        return plugins;
    }
}


//==============================================================================
NodeRenderContext::NodeRenderContext (Renderer::RenderTask& owner_, Renderer::Parameters& p,
                                      std::unique_ptr<Node> n,
                                      std::unique_ptr<tracktion_graph::PlayHead> playHead_,
                                      std::unique_ptr<tracktion_graph::PlayHeadState> playHeadState_,
                                      std::unique_ptr<ProcessState> processState_,
                                      juce::AudioFormatWriter::ThreadedWriter::IncomingDataReceiver* sourceToUpdate_)
    : owner (owner_),
      r (p), originalParams (p),
      playHead (std::move (playHead_)),
      playHeadState (std::move (playHeadState_)),
      processState (std::move (processState_)),
      status (juce::Result::ok()),
      ditherers (256, r.bitDepth),
      sourceToUpdate (sourceToUpdate_)
{
    CRASH_TRACER
    TRACKTION_ASSERT_MESSAGE_THREAD
    jassert (r.engine != nullptr);
    jassert (r.edit != nullptr);
    jassert (r.time.getLength() > 0.0);

    nodePlayer = std::make_unique<TracktionNodePlayer> (std::move (n), *processState);

    if (r.edit->getTransport().isPlayContextActive())
    {
        jassertfalse;
        TRACKTION_LOG_ERROR("Rendering whilst attached to audio device");
    }

    if (r.shouldNormalise || r.trimSilenceAtEnds || r.shouldNormaliseByRMS)
    {
        needsToNormaliseAndTrim = true;

        r.audioFormat = r.engine->getAudioFileFormatManager().getFrozenFileFormat();

        intermediateFile = std::make_unique<juce::TemporaryFile> (r.destFile.withFileExtension (r.audioFormat->getFileExtensions()[0]));
        r.destFile = intermediateFile->getFile();

        r.shouldNormalise = false;
        r.trimSilenceAtEnds = false;
        r.shouldNormaliseByRMS = false;
    }

    numOutputChans = 2;

    {
        auto props = nodePlayer->getNode()->getNodeProperties();

        if (! props.hasAudio)
        {
            status = juce::Result::fail (TRANS("Didn't find any audio to render"));
            return;
        }

        if (r.mustRenderInMono || (r.canRenderInMono && (props.numberOfChannels < 2)))
            numOutputChans = 1;
    }

    AudioFileUtils::addBWAVStartToMetadata (r.metadata, (int64_t) (r.time.getStart() * r.sampleRateForAudio));

    writer = std::make_unique<AudioFileWriter> (AudioFile (*originalParams.engine, r.destFile),
                                                r.audioFormat, numOutputChans, r.sampleRateForAudio,
                                                r.bitDepth, r.metadata, r.quality);

    if (r.destFile != juce::File() && ! writer->isOpen())
    {
        status = juce::Result::fail (TRANS("Couldn't write to target file"));
        return;
    }

    thresholdForStopping = dbToGain (-70.0f);

    renderingBuffer.setSize (numOutputChans, r.blockSizeForAudio + 256);
    blockLength = r.blockSizeForAudio / r.sampleRateForAudio;

    // number of blank blocks to play before starting, to give plugins time to warm up
    numPreRenderBlocks = (int) ((r.sampleRateForAudio / 2) / r.blockSizeForAudio + 1);

    // how long each block must take in real-time
    realTimePerBlock = (int) (blockLength * 1000.0 + 0.99);
    lastTime = juce::Time::getMillisecondCounterHiRes();
    sleepCounter = 10;

    currentTempoPosition = std::make_unique<TempoSequencePosition> (r.edit->tempoSequence);

    peak = 0.0001f;
    rmsTotal = 0.0;
    rmsNumSamps = 0;
    numNonZeroSamps = 0;
    streamTime = r.time.getStart();

    precount = numPreRenderBlocks;
    streamTime -= precount * blockLength;

    plugins = findAllPlugins (*nodePlayer->getNode());

    // Set the realtime property before preparing to play
    Renderer::RenderTask::setAllPluginsRealtime (plugins, r.realTimeRender);
    nodePlayer->prepareToPlay (r.sampleRateForAudio, r.blockSizeForAudio);
    Renderer::RenderTask::flushAllPlugins (plugins, r.sampleRateForAudio, r.blockSizeForAudio);

    samplesTrimmed = 0;
    hasStartedSavingToFile = ! r.trimSilenceAtEnds;

    playHead->stop();
    playHead->setPosition (timeToSample (r.time.getStart(), r.sampleRateForAudio));

    samplesToWrite = juce::roundToInt ((r.time.getLength() + r.endAllowance) * r.sampleRateForAudio);

    if (sourceToUpdate != nullptr)
        sourceToUpdate->reset (numOutputChans, r.sampleRateForAudio, samplesToWrite);
}

NodeRenderContext::~NodeRenderContext()
{
    CRASH_TRACER
    r.resultMagnitude = owner.params.resultMagnitude = peak;
    r.resultRMS = owner.params.resultRMS = rmsNumSamps > 0 ? (float) (rmsTotal / rmsNumSamps) : 0.0f;
    r.resultAudioDuration = owner.params.resultAudioDuration = float (numNonZeroSamps / owner.params.sampleRateForAudio);

    playHead->stop();
    Renderer::RenderTask::setAllPluginsRealtime (plugins, true);

    if (writer != nullptr)
        writer->closeForWriting();

    callBlocking ([this] { nodePlayer->setNode (nullptr); });

    if (needsToNormaliseAndTrim)
        owner.performNormalisingAndTrimming (originalParams, r);
}

bool NodeRenderContext::renderNextBlock (std::atomic<float>& progressToUpdate)
{
    CRASH_TRACER
    jassert (! r.edit->getTransport().isPlayContextActive());

    if (--sleepCounter <= 0)
    {
        sleepCounter = sleepCounterMax;
        juce::Thread::sleep (1);
    }

    if (owner.shouldExit())
    {
        writer->closeForWriting();
        r.destFile.deleteFile();

        playHead->stop();
        Renderer::RenderTask::setAllPluginsRealtime (plugins, true);

        return true;
    }

    auto blockEnd = streamTime + blockLength;

    if (precount > 0)
        blockEnd = juce::jmin (r.time.getStart(), blockEnd);

    if (precount > numPreRenderBlocks / 2)
        playHead->setPosition (timeToSample (streamTime, r.sampleRateForAudio));
    else if (precount == numPreRenderBlocks / 2)
        playHead->playSyncedToRange ({ timeToSample (streamTime, r.sampleRateForAudio), std::numeric_limits<int64_t>::max() });

    if (precount == 0)
    {
        streamTime = r.time.getStart();
        playHead->playSyncedToRange (timeToSample (EditTimeRange (streamTime, Edit::maximumLength), r.sampleRateForAudio));
        playHeadState->update (tracktion_graph::timeToSample (EditTimeRange (streamTime, blockEnd), r.sampleRateForAudio));
    }

    if (r.realTimeRender)
    {
        auto timeNow = juce::Time::getMillisecondCounterHiRes();
        auto timeToWait = (int) (realTimePerBlock - (timeNow - lastTime));
        lastTime = timeNow;

        if (timeToWait > 0)
            juce::Thread::sleep (timeToWait);
    }

    currentTempoPosition->setTime (streamTime);

    resetFP();

    const EditTimeRange streamTimeRange (streamTime, blockEnd);

    // Update modifier timers
    r.edit->updateModifierTimers (streamTime, r.blockSizeForAudio);

    // Wait for any nodes to render their sources or proxies
    auto leafNodesReady = [this]
    {
        for (auto node : getNodes (*nodePlayer->getNode(), VertexOrdering::postordering))
            if (node->getDirectInputNodes().empty() && ! node->isReadyToProcess())
                return false;
        
        return true;
    }();
    
    while (! (leafNodesReady || owner.shouldExit()))
        return false;

    renderingBuffer.clear();
    midiBuffer.clear();
    const auto referenceSampleRange = tracktion_graph::timeToSample (streamTimeRange, originalParams.sampleRateForAudio);
    juce::dsp::AudioBlock<float> destBlock (renderingBuffer.getArrayOfWritePointers(),
                                            (size_t) renderingBuffer.getNumChannels(), (size_t) referenceSampleRange.getLength());
    nodePlayer->process ({ referenceSampleRange, { destBlock, midiBuffer} });

    streamTime = blockEnd;

    if (precount <= 0)
    {
        CRASH_TRACER
        jassert (playHeadState->isContiguousWithPreviousBlock());
        int numSamplesDone = (int) juce::jmin (samplesToWrite, (int64_t) r.blockSizeForAudio);
        samplesToWrite -= numSamplesDone;

        if (r.ditheringEnabled && r.bitDepth < 32)
            ditherers.apply (renderingBuffer, r.blockSizeForAudio);

        auto mag = renderingBuffer.getMagnitude (0, numSamplesDone);
        peak = juce::jmax (peak, mag);

        if (! hasStartedSavingToFile)
            hasStartedSavingToFile = (mag > 0.0f);

        for (int i = renderingBuffer.getNumChannels(); --i >= 0;)
        {
            rmsTotal += renderingBuffer.getRMSLevel (i, 0, numSamplesDone);
            ++rmsNumSamps;
        }

        for (int i = numSamplesDone; --i >= 0;)
            if (renderingBuffer.getMagnitude (i, 1) > 0.0001)
                numNonZeroSamps++;

        if (! hasStartedSavingToFile)
            samplesTrimmed += r.blockSizeForAudio;

        if (sourceToUpdate != nullptr && numSamplesDone > 0)
        {
            float* chans[32];

            for (int i = 0; i < numOutputChans; ++i)
                chans[i] = renderingBuffer.getWritePointer (i, 0);

            const juce::AudioBuffer<float> buffer (chans, numOutputChans, numSamplesDone);
            auto samplesDone = int64_t ((streamTime - r.time.getStart()) * r.sampleRateForAudio);
            sourceToUpdate->addBlock (samplesDone, buffer, 0, numSamplesDone);
        }

        // NB buffer gets trashed by this call
        if (numSamplesDone > 0 && hasStartedSavingToFile
             && writer->isOpen()
             && ! writer->appendBuffer (renderingBuffer, numSamplesDone))
            return true;
    }
    else
    {
        // for the pre-count blocks, sleep to give things a chance to get going
        juce::Thread::sleep ((int) (blockLength * 1000));
    }

    if (streamTime > r.time.getEnd() + r.endAllowance
        || (streamTime > r.time.getEnd()
            && renderingBuffer.getMagnitude (0, r.blockSizeForAudio) <= thresholdForStopping))
        return true;

    auto prog = (float) ((streamTime - r.time.getStart()) / juce::jmax (1.0, r.time.getLength()));

    if (needsToNormaliseAndTrim)
        prog *= 0.9f;

    jassert (! std::isnan (prog));
    progressToUpdate = juce::jlimit (0.0f, 1.0f, prog);
    --precount;

    return false;
}

} // namespace tracktion_engine
