/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2018
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

namespace tracktion_engine
{

#if TRACKTION_GRAPH_PERFORMANCE_TESTS

using namespace tracktion_graph;

//==============================================================================
//==============================================================================
class PerformanceTests : public juce::UnitTest
{
public:
    PerformanceTests()
        : juce::UnitTest ("Performance Tests", "tracktion_graph_performance")
    {
    }
    
    void runTest() override
    {
        using namespace tracktion_graph;
        test_utilities::TestSetup ts;
        ts.sampleRate = 96000.0;
        ts.blockSize = 128;
        
        using namespace benchmark_utilities;
        BenchmarkOptions opts;
        opts.testSetup = ts;
        
        for (auto strategy : test_utilities::getThreadPoolStrategies())
        {
            opts.poolType = strategy;
            
            opts.isMultiThreaded = MultiThreaded::no;
            runWaveRendering (30.0, 20, 12, true, opts);
            opts.isMultiThreaded = MultiThreaded::yes;
            runWaveRendering (30.0, 20, 12, false, opts);
            
            opts.isMultiThreaded = MultiThreaded::no;
            runWaveRendering (30.0, 20, 12, true, opts);
            opts.isMultiThreaded = MultiThreaded::yes;
            runWaveRendering (30.0, 20, 12, false, opts);
        }
    }

private:
    //==============================================================================
    //==============================================================================
    void runWaveRendering (double durationInSeconds,
                           int numTracks,
                           int numFilesPerTrack,
                           bool useSingleFile,
                           benchmark_utilities::BenchmarkOptions opts)
    {
        // Create Edit with 20 tracks
        // Create 12 5s files per track
        // Render the whole thing
        using namespace tracktion_graph;
        using namespace test_utilities;
        auto& engine = *tracktion_engine::Engine::getEngines()[0];
        const auto description = benchmark_utilities::getDescription (opts)
                                    + juce::String (useSingleFile ? ", single file" : ", multiple files");
        
        tracktion_graph::PlayHead playHead;
        tracktion_graph::PlayHeadState playHeadState { playHead };
        ProcessState processState { playHeadState };

        //===
        beginTest ("Wave Edit - creation: " + description);
        const double durationOfFile = durationInSeconds / numFilesPerTrack;
        auto context = createTestContext (engine, numTracks, numFilesPerTrack, durationOfFile, opts.testSetup.sampleRate, opts.testSetup.random, useSingleFile);
        expect (context.edit != nullptr);
        opts.edit = context.edit.get();

        const auto totalNumFiles = size_t (numTracks * numFilesPerTrack);
        expect (useSingleFile || (context.files.size() == totalNumFiles));
        expectWithinAbsoluteError (context.edit->getLength(), durationInSeconds, 0.01);

        renderEdit (*this, opts);
    }
    
    //==============================================================================
    //==============================================================================
    struct EditTestContext
    {
        std::unique_ptr<Edit> edit;
        std::vector<std::unique_ptr<juce::TemporaryFile>> files;
    };
    
    static EditTestContext createTestContext (Engine& engine, int numTracks, int numFilesPerTrack, double durationOfFile, double sampleRate, juce::Random& r, bool useSingleFile)
    {
        auto edit = Edit::createSingleTrackEdit (engine);
        std::vector<std::unique_ptr<juce::TemporaryFile>> files;

        edit->ensureNumberOfAudioTracks (numTracks);
        
        if (useSingleFile)
            files.push_back (tracktion_graph::test_utilities::getSinFile<juce::WavAudioFormat> (sampleRate, durationOfFile, 2, 220.0f));

        for (auto t : getAudioTracks (*edit))
        {
            for (int i = 0; i < numFilesPerTrack; ++i)
            {
                if (! useSingleFile)
                {
                    const float frequency = (float) r.nextInt ({ 110, 880 });
                    auto file = tracktion_graph::test_utilities::getSinFile<juce::WavAudioFormat> (sampleRate, durationOfFile, 2, frequency);
                    files.push_back (std::move (file));
                }

                auto& file = files.back();
                const auto timeRange = EditTimeRange::withStartAndLength (i * durationOfFile, durationOfFile);
                auto waveClip = t->insertWaveClip (file->getFile().getFileName(), file->getFile(),
                                                   {{ timeRange }}, false);
                waveClip->setGainDB (gainToDb (1.0f / numTracks));
            }
        }
                
        return { std::move (edit), std::move (files) };
    }
};

static PerformanceTests performanceTests;

#endif

} // namespace tracktion_engine
