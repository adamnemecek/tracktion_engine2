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

namespace IDs
{
    #define DECLARE_ID(name)  const juce::Identifier name (#name);

    DECLARE_ID (ROOT)
    DECLARE_ID (ACTIVE)
    DECLARE_ID (LIBRARY)
    DECLARE_ID (FOLDER)
    DECLARE_ID (PROJECT)
    DECLARE_ID (project)
    DECLARE_ID (file)
    DECLARE_ID (MACROS)
    DECLARE_ID (MACRO)
    DECLARE_ID (key)
    DECLARE_ID (EDIT)
    DECLARE_ID (name)
    DECLARE_ID (type)
    DECLARE_ID (__TEXT)
    DECLARE_ID (NAME)
    DECLARE_ID (fadeIn)
    DECLARE_ID (fadeOut)
    DECLARE_ID (VIDEO)
    DECLARE_ID (videoOffset)
    DECLARE_ID (level)
    DECLARE_ID (automationLocked)
    DECLARE_ID (recordPunchInOut)
    DECLARE_ID (endToEnd)
    DECLARE_ID (midiTimecodeOffset)
    DECLARE_ID (midiTimecodeEnabled)
    DECLARE_ID (midiTimecodeIgnoringHours)
    DECLARE_ID (midiTimecodeSourceDevice)
    DECLARE_ID (midiMachineControlSourceDevice)
    DECLARE_ID (midiMachineControlDestDevice)
    DECLARE_ID (fadeInType)
    DECLARE_ID (fadeOutType)
    DECLARE_ID (videoSource)
    DECLARE_ID (videoMuted)
    DECLARE_ID (videoActive)
    DECLARE_ID (active)
    DECLARE_ID (emphasiseBars)
    DECLARE_ID (onlyRecording)
    DECLARE_ID (outputDevice)
    DECLARE_ID (bus)
    DECLARE_ID (CONTROLLERMAPPINGS)
    DECLARE_ID (MAP)
    DECLARE_ID (projectID)
    DECLARE_ID (id)
    DECLARE_ID (volume)
    DECLARE_ID (left)
    DECLARE_ID (right)
    DECLARE_ID (channel)
    DECLARE_ID (param)
    DECLARE_ID (pluginID)
    DECLARE_ID (AUTOMAPXML)
    DECLARE_ID (guid)
    DECLARE_ID (INPUTDEVICES)
    DECLARE_ID (INPUTDEVICE)
    DECLARE_ID (INPUTDEVICEINSTANCE)
    DECLARE_ID (INPUTDEVICEDESTINATION)
    DECLARE_ID (sourceTrack)
    DECLARE_ID (targetTrack)
    DECLARE_ID (targetIndex)
    DECLARE_ID (armed)
    DECLARE_ID (ID3VORBISMETADATA)
    DECLARE_ID (TRACK)
    DECLARE_ID (TRACKSET)
    DECLARE_ID (TEMPOTRACK)
    DECLARE_ID (FOLDERTRACK)
    DECLARE_ID (MARKERTRACK)
    DECLARE_ID (AUTOMATIONTRACK)
    DECLARE_ID (AUTOMATIONSET)
    DECLARE_ID (CLICKTRACK)
    DECLARE_ID (CHORDTRACK)
    DECLARE_ID (MASTERTRACK)
    DECLARE_ID (MARKER)
    DECLARE_ID (MASTERPLUGINS)
    DECLARE_ID (PITCHSEQUENCE)
    DECLARE_ID (number)
    DECLARE_ID (MASTERVOLUME)
    DECLARE_ID (PITCH)
    DECLARE_ID (trackType)
    DECLARE_ID (album)
    DECLARE_ID (artist)
    DECLARE_ID (comment)
    DECLARE_ID (date)
    DECLARE_ID (time)
    DECLARE_ID (genre)
    DECLARE_ID (title)
    DECLARE_ID (start)
    DECLARE_ID (pitch)
    DECLARE_ID (accidentalsSharp)
    DECLARE_ID (scale)
    DECLARE_ID (trackNumber)
    DECLARE_ID (automationRead)
    DECLARE_ID (appVersion)
    DECLARE_ID (modifiedBy)
    DECLARE_ID (creationTime)
    DECLARE_ID (lastSignificantChange)
    DECLARE_ID (TEMPO)
    DECLARE_ID (TIMESIG)
    DECLARE_ID (TEMPOSEQUENCE)
    DECLARE_ID (startBeat)
    DECLARE_ID (bpm)
    DECLARE_ID (curve)
    DECLARE_ID (numerator)
    DECLARE_ID (denominator)
    DECLARE_ID (triplets)
    DECLARE_ID (fps)
    DECLARE_ID (timecodeFormat)
    DECLARE_ID (VSTDATA)
    DECLARE_ID (RACK)
    DECLARE_ID (RACKS)
    DECLARE_ID (PLUGININSTANCE)
    DECLARE_ID (INPUT)
    DECLARE_ID (OUTPUT)
    DECLARE_ID (OUTPUTS)
    DECLARE_ID (LAYOUT)
    DECLARE_ID (BUS)
    DECLARE_ID (WINDOWSTATE)
    DECLARE_ID (index)
    DECLARE_ID (layout)
    DECLARE_ID (parameters)
    DECLARE_ID (CURVESECTION)
    DECLARE_ID (TEMPOCURVESECTION)
    DECLARE_ID (AUTOMATIONCURVE)
    DECLARE_ID (POINT)
    DECLARE_ID (AUTOMATIONSOURCE)
    DECLARE_ID (MODIFIERS)
    DECLARE_ID (MODIFIERASSIGNMENTS)
    DECLARE_ID (numSteps)
    DECLARE_ID (syncType)
    DECLARE_ID (stepData)
    DECLARE_ID (stepDepth)
    DECLARE_ID (smooth)
    DECLARE_ID (paramName)
    DECLARE_ID (bipolar)
    DECLARE_ID (paramID)
    DECLARE_ID (lfoSource)
    DECLARE_ID (shownOn)
    DECLARE_ID (t)
    DECLARE_ID (v)
    DECLARE_ID (c)
    DECLARE_ID (m)
    DECLARE_ID (rackType)
    DECLARE_ID (windowPos)
    DECLARE_ID (windowX)
    DECLARE_ID (windowY)
    DECLARE_ID (windowLocked)
    DECLARE_ID (src)
    DECLARE_ID (dst)
    DECLARE_ID (srcPin)
    DECLARE_ID (dstPin)
    DECLARE_ID (x)
    DECLARE_ID (y)
    DECLARE_ID (uid)
    DECLARE_ID (uniqueId)
    DECLARE_ID (filename)
    DECLARE_ID (enabled)
    DECLARE_ID (manufacturer)
    DECLARE_ID (programNum)
    DECLARE_ID (dry)
    DECLARE_ID (wet)
    DECLARE_ID (roomSize)
    DECLARE_ID (damp)
    DECLARE_ID (leftTo)
    DECLARE_ID (leftInDb)
    DECLARE_ID (rightTo)
    DECLARE_ID (rightInDb)
    DECLARE_ID (leftFrom)
    DECLARE_ID (leftOutDb)
    DECLARE_ID (rightFrom)
    DECLARE_ID (rightOutDb)
    DECLARE_ID (panLaw)
    DECLARE_ID (busNum)
    DECLARE_ID (auxSendSliderPos)
    DECLARE_ID (lastVolumeBeforeMuteDb)
    DECLARE_ID (depthMs)
    DECLARE_ID (speedHz)
    DECLARE_ID (width)
    DECLARE_ID (mixProportion)
    DECLARE_ID (showMidi)
    DECLARE_ID (depth)
    DECLARE_ID (rate)
    DECLARE_ID (feedback)
    DECLARE_ID (mix)
    DECLARE_ID (body)
    DECLARE_ID (applyToMidi)
    DECLARE_ID (ignoreVca)
    DECLARE_ID (polarity)
    DECLARE_ID (remapOnTempoChange)
    DECLARE_ID (quickParamName)
    DECLARE_ID (masterPluginID)
    DECLARE_ID (sidechainSourceID)
    DECLARE_ID (startTime)
    DECLARE_ID (CONNECTION)
    DECLARE_ID (gainDb)
    DECLARE_ID (srcChan)
    DECLARE_ID (dstChan)
    DECLARE_ID (keyNote)
    DECLARE_ID (minNote)
    DECLARE_ID (maxNote)
    DECLARE_ID (openEnded)
    DECLARE_ID (SOUND)
    DECLARE_ID (threshold)
    DECLARE_ID (inputDb)
    DECLARE_ID (outputDb)
    DECLARE_ID (ratio)
    DECLARE_ID (attack)
    DECLARE_ID (release)
    DECLARE_ID (SIDECHAINCONNECTION)
    DECLARE_ID (SIDECHAINCONNECTIONS)
    DECLARE_ID (sidechainTrigger)
    DECLARE_ID (sidechainDb)
    DECLARE_ID (frequency)
    DECLARE_ID (mode)
    DECLARE_ID (loFreq)
    DECLARE_ID (loGain)
    DECLARE_ID (loQ)
    DECLARE_ID (hiFreq)
    DECLARE_ID (hiGain)
    DECLARE_ID (hiQ)
    DECLARE_ID (midFreq1)
    DECLARE_ID (midGain1)
    DECLARE_ID (midQ1)
    DECLARE_ID (midFreq2)
    DECLARE_ID (midGain2)
    DECLARE_ID (midQ2)
    DECLARE_ID (phaseInvert)
    DECLARE_ID (AUDIOCLIP)
    DECLARE_ID (MIDICLIP)
    DECLARE_ID (MARKERCLIP)
    DECLARE_ID (STEPCLIP)
    DECLARE_ID (CHORDCLIP)
    DECLARE_ID (EDITCLIP)
    DECLARE_ID (CLIPSET)
    DECLARE_ID (MIDINOTES)
    DECLARE_ID (length)
    DECLARE_ID (offset)
    DECLARE_ID (speed)
    DECLARE_ID (source)
    DECLARE_ID (colour)
    DECLARE_ID (hidden)
    DECLARE_ID (process)
    DECLARE_ID (sync)
    DECLARE_ID (showingTakes)
    DECLARE_ID (markerID)
    DECLARE_ID (semitonesUp)
    DECLARE_ID (mappings)
    DECLARE_ID (device)
    DECLARE_ID (channelL)
    DECLARE_ID (channelR)
    DECLARE_ID (manualAdjustMs)
    DECLARE_ID (STEPCLIPVIEWSTATE)
    DECLARE_ID (PATTERN)
    DECLARE_ID (CHANNEL)
    DECLARE_ID (PATTERNS)
    DECLARE_ID (CHANNELS)
    DECLARE_ID (repeatSequence)
    DECLARE_ID (numNotes)
    DECLARE_ID (noteLength)
    DECLARE_ID (noteNumber)
    DECLARE_ID (noteValue)
    DECLARE_ID (note)
    DECLARE_ID (velocity)
    DECLARE_ID (groove)
    DECLARE_ID (sequence)
    DECLARE_ID (state)
    DECLARE_ID (pattern)
    DECLARE_ID (velocities)
    DECLARE_ID (gates)
    DECLARE_ID (probabilities)
    DECLARE_ID (ramped)
    DECLARE_ID (cursorpos)
    DECLARE_ID (viewleft)
    DECLARE_ID (viewright)
    DECLARE_ID (tracktop)
    DECLARE_ID (markIn)
    DECLARE_ID (markOut)
    DECLARE_ID (pluginAreaWidth)
    DECLARE_ID (sidePanelsWidth)
    DECLARE_ID (midiEditorHeight)
    DECLARE_ID (mixerPanelHeight)
    DECLARE_ID (midiEditorShown)
    DECLARE_ID (mixerPanelShown)
    DECLARE_ID (sidePanelsShown)
    DECLARE_ID (sidePanelsCount)
    DECLARE_ID (rackEditorHeight)
    DECLARE_ID (searchPanelTagHeight)
    DECLARE_ID (midiControllerHeight)
    DECLARE_ID (midiVelocityHeight)
    DECLARE_ID (stepVelocityHeight)
    DECLARE_ID (stepVelocityVisible)
    DECLARE_ID (stepRandomVisible)
    DECLARE_ID (markerMode)
    DECLARE_ID (lastMarkerMode)
    DECLARE_ID (currentSidePanel)
    DECLARE_ID (scrollWhenPlaying)
    DECLARE_ID (scrollSuspended)
    DECLARE_ID (scrollSmoothly)
    DECLARE_ID (loopPlayback)
    DECLARE_ID (snapToTimecode)
    DECLARE_ID (showTaggedTracks)
    DECLARE_ID (enabledTrackTags)
    DECLARE_ID (disabledSearchLibraries)
    DECLARE_ID (tempoTrackVisible)
    DECLARE_ID (chordTrackVisible)
    DECLARE_ID (controlsVisible)
    DECLARE_ID (inputsVisible)
    DECLARE_ID (pluginsVisible)
    DECLARE_ID (trackCompsVisible)
    DECLARE_ID (trackCompsEditable)
    DECLARE_ID (minimalTransportBar)
    DECLARE_ID (lockedClips)
    DECLARE_ID (hiddenClips)
    DECLARE_ID (TRACKCOMPS)
    DECLARE_ID (TRACKCOMP)
    DECLARE_ID (track)
    DECLARE_ID (end)
    DECLARE_ID (includedColour)
    DECLARE_ID (excludedColour)
    DECLARE_ID (previewIndex)
    DECLARE_ID (crossfadeLength)
    DECLARE_ID (gain)
    DECLARE_ID (mute)
    DECLARE_ID (pan)
    DECLARE_ID (autoFadeIn)
    DECLARE_ID (autoFadeOut)
    DECLARE_ID (autoCrossfade)
    DECLARE_ID (fadeInBehaviour)
    DECLARE_ID (fadeOutBehaviour)
    DECLARE_ID (loopStart)
    DECLARE_ID (loopLength)
    DECLARE_ID (loopStartBeats)
    DECLARE_ID (loopLengthBeats)
    DECLARE_ID (channels)
    DECLARE_ID (elastiqueMode)
    DECLARE_ID (elastiqueOptions)
    DECLARE_ID (timeStretch)
    DECLARE_ID (stretchMode)
    DECLARE_ID (pitchChange)
    DECLARE_ID (autoPitch)
    DECLARE_ID (autoPitchMode)
    DECLARE_ID (autoTempo)
    DECLARE_ID (warpTime)
    DECLARE_ID (isReversed)
    DECLARE_ID (transpose)
    DECLARE_ID (autoDetectBeats)
    DECLARE_ID (beatSensitivity)
    DECLARE_ID (groupID)
    DECLARE_ID (linkID)
    DECLARE_ID (MELODYNEFILEREADER)
    DECLARE_ID (ARADOCUMENT)
    DECLARE_ID (EFFECTS)
    DECLARE_ID (EFFECT)
    DECLARE_ID (effectsVisible)
    DECLARE_ID (currentCurve)
    DECLARE_ID (hash)
    DECLARE_ID (processMidiWhenMuted)
    DECLARE_ID (LOOPINFO)
    DECLARE_ID (numBeats)
    DECLARE_ID (rootNote)
    DECLARE_ID (inMarker)
    DECLARE_ID (outMarker)
    DECLARE_ID (oneShot)
    DECLARE_ID (LOOPPOINTS)
    DECLARE_ID (LOOPPOINT)
    DECLARE_ID (value)
    DECLARE_ID (TAGS)
    DECLARE_ID (TAG)
    DECLARE_ID (currentTake)
    DECLARE_ID (sendProgramChange)
    DECLARE_ID (quantisation)
    DECLARE_ID (QUANTISATION)
    DECLARE_ID (amount)
    DECLARE_ID (quantiseNoteOffs)
    DECLARE_ID (GROOVE)
    DECLARE_ID (current)
    DECLARE_ID (volDb)
    DECLARE_ID (sendBankChange)
    DECLARE_ID (grooveStrength)
    DECLARE_ID (showingNoteAutomation)
    DECLARE_ID (mpeMode)
    DECLARE_ID (originalLength)
    DECLARE_ID (loopedSequenceType)
    DECLARE_ID (TAKES)
    DECLARE_ID (TAKE)
    DECLARE_ID (COMPS)
    DECLARE_ID (isComp)
    DECLARE_ID (COMPSECTION)
    DECLARE_ID (takeIndex)
    DECLARE_ID (endTime)
    DECLARE_ID (WARPTIME)
    DECLARE_ID (warpEndMarkerTime)
    DECLARE_ID (WARPMARKERS)
    DECLARE_ID (WARPMARKER)
    DECLARE_ID (sourceTime)
    DECLARE_ID (SEQUENCE)
    DECLARE_ID (channelNumber)
    DECLARE_ID (ver)
    DECLARE_ID (NOTE)
    DECLARE_ID (p)
    DECLARE_ID (b)
    DECLARE_ID (l)
    DECLARE_ID (converted)
    DECLARE_ID (NA)
    DECLARE_ID (CONTROL)
    DECLARE_ID (val)
    DECLARE_ID (metadata)
    DECLARE_ID (SYSEX)
    DECLARE_ID (data)
    DECLARE_ID (PITCHBEND)
    DECLARE_ID (PRESSURE)
    DECLARE_ID (TIMBRE)
    DECLARE_ID (timb)
    DECLARE_ID (pres)
    DECLARE_ID (bend)
    DECLARE_ID (lift)
    DECLARE_ID (copyColour)
    DECLARE_ID (trimToMarker)
    DECLARE_ID (renderEnabled)
    DECLARE_ID (RENDER)
    DECLARE_ID (renderType)
    DECLARE_ID (renderTracks)
    DECLARE_ID (renderDestFile)
    DECLARE_ID (renderCreateMidiFile)
    DECLARE_ID (renderFormat)
    DECLARE_ID (renderStereo)
    DECLARE_ID (renderSampleRate)
    DECLARE_ID (renderBitDepth)
    DECLARE_ID (renderQualityIndex)
    DECLARE_ID (renderRMSLevelDb)
    DECLARE_ID (renderPeakLevelDb)
    DECLARE_ID (renderRemoveSilence)
    DECLARE_ID (renderNormalise)
    DECLARE_ID (renderDither)
    DECLARE_ID (renderAdjustBasedOnRMS)
    DECLARE_ID (renderMarkedRegion)
    DECLARE_ID (renderSelectedTracks)
    DECLARE_ID (renderSelectedClips)
    DECLARE_ID (renderTracksToSeparateFiles)
    DECLARE_ID (renderRealTime)
    DECLARE_ID (renderPlugins)
    DECLARE_ID (renderOptions)
    DECLARE_ID (addRenderToLibrary)
    DECLARE_ID (reverseRender)
    DECLARE_ID (renderAddMetadata)
    DECLARE_ID (height)
    DECLARE_ID (currentAutoParamPluginID)
    DECLARE_ID (currentAutoParamTag)
    DECLARE_ID (imageIdOrData)
    DECLARE_ID (expanded)
    DECLARE_ID (solo)
    DECLARE_ID (soloIsolate)
    DECLARE_ID (frozen)
    DECLARE_ID (frozenIndividually)
    DECLARE_ID (maxInputs)
    DECLARE_ID (compGroup)
    DECLARE_ID (midiVProp)
    DECLARE_ID (midiVOffset)
    DECLARE_ID (midiNoteMap)
    DECLARE_ID (ghostTracks)
    DECLARE_ID (OUTPUTDEVICES)
    DECLARE_ID (DEVICE)
    DECLARE_ID (latency)
    DECLARE_ID (inputDevice)
    DECLARE_ID (PRESETS)
    DECLARE_ID (PRESET)
    DECLARE_ID (description)
    DECLARE_ID (tags)
    DECLARE_ID (builtIn)
    DECLARE_ID (INPUTS)
    DECLARE_ID (rack)
    DECLARE_ID (DATA)
    DECLARE_ID (LOOPS)
    DECLARE_ID (LOOP)
    DECLARE_ID (path)
    DECLARE_ID (size)
    DECLARE_ID (deleted)
    DECLARE_ID (icon)
    DECLARE_ID (format)
    DECLARE_ID (category)
    DECLARE_ID (idString)
    DECLARE_ID (disabled)
    DECLARE_ID (PLUGINS)
    DECLARE_ID (PLUGIN)
    DECLARE_ID (LFO)
    DECLARE_ID (MIDITRACKER)
    DECLARE_ID (BREAKPOINTOSCILLATOR)
    DECLARE_ID (STEP)
    DECLARE_ID (ENVELOPEFOLLOWER)
    DECLARE_ID (RANDOM)
    DECLARE_ID (LFOS)
    DECLARE_ID (wave)
    DECLARE_ID (beat)
    DECLARE_ID (phase)
    DECLARE_ID (intensity)
    DECLARE_ID (rateType)
    DECLARE_ID (hold)
    DECLARE_ID (lowPassEnabled)
    DECLARE_ID (highPassEnabled)
    DECLARE_ID (lowPassFrequency)
    DECLARE_ID (highPassFrequency)
    DECLARE_ID (shape)
    DECLARE_ID (numActivePoints)
    DECLARE_ID (stageZeroValue)
    DECLARE_ID (stageOneValue)
    DECLARE_ID (stageOneTime)
    DECLARE_ID (stageOneCurve)
    DECLARE_ID (stageTwoValue)
    DECLARE_ID (stageTwoTime)
    DECLARE_ID (stageTwoCurve)
    DECLARE_ID (stageThreeValue)
    DECLARE_ID (stageThreeTime)
    DECLARE_ID (stageThreeCurve)
    DECLARE_ID (stageFourValue)
    DECLARE_ID (stageFourTime)
    DECLARE_ID (stageFourCurve)
    DECLARE_ID (root)
    DECLARE_ID (spread)
    DECLARE_ID (NODES)
    DECLARE_ID (NODE)
    DECLARE_ID (midi)
    DECLARE_ID (PATTERNGENERATOR)
    DECLARE_ID (PROGRESSION)
    DECLARE_ID (PROGRESSIONITEM)
    DECLARE_ID (autoUpdate)
    DECLARE_ID (allNotes)
    DECLARE_ID (octave)
    DECLARE_ID (octaveUp)
    DECLARE_ID (octaveDown)
    DECLARE_ID (inversion)
    DECLARE_ID (pitches)
    DECLARE_ID (chordName)
    DECLARE_ID (arpUpDown)
    DECLARE_ID (arpPlayroot)
    DECLARE_ID (arpPatternLength)
    DECLARE_ID (arpStle)
    DECLARE_ID (arpSteps)
    DECLARE_ID (melodyNoteLength)
    DECLARE_ID (gate)
    DECLARE_ID (scaleType)
    DECLARE_ID (scaleRoot)
    DECLARE_ID (CHORDPATTERN)
    DECLARE_ID (BASSPATTERN)
    DECLARE_ID (user)
    DECLARE_ID (progression)
    DECLARE_ID (BAR)
    DECLARE_ID (MACROPARAMETERS)
    DECLARE_ID (MACROPARAMETER)
    DECLARE_ID (MAPPEDPARAMETER)
    DECLARE_ID (TRANSPORT)
    DECLARE_ID (position)
    DECLARE_ID (loopPoint1)
    DECLARE_ID (loopPoint2)
    DECLARE_ID (playing)
    DECLARE_ID (recording)
    DECLARE_ID (looping)
    DECLARE_ID (MODMATRIX)
    DECLARE_ID (MODMATRIXITEM)
    DECLARE_ID (mpe)
    DECLARE_ID (ampAttack)
    DECLARE_ID (ampDecay)
    DECLARE_ID (ampSustain)
    DECLARE_ID (ampRelease)
    DECLARE_ID (ampVelocity)
    DECLARE_ID (ampAnalog)
    DECLARE_ID (filterAttack)
    DECLARE_ID (filterDecay)
    DECLARE_ID (filterSustain)
    DECLARE_ID (filterRelease)
    DECLARE_ID (filterFreq)
    DECLARE_ID (filterResonance)
    DECLARE_ID (filterAmount)
    DECLARE_ID (filterKey)
    DECLARE_ID (filterVelocity)
    DECLARE_ID (filterType)
    DECLARE_ID (filterSlope)
    DECLARE_ID (filterQ)
    DECLARE_ID (waveShape)
    DECLARE_ID (tune)
    DECLARE_ID (fineTune)
    DECLARE_ID (pulseWidth)
    DECLARE_ID (voices)
    DECLARE_ID (detune)
    DECLARE_ID (distortionOn)
    DECLARE_ID (reverbOn)
    DECLARE_ID (delayOn)
    DECLARE_ID (chorusOn)
    DECLARE_ID (distortion)
    DECLARE_ID (reverbSize)
    DECLARE_ID (reverbDamping)
    DECLARE_ID (reverbMix)
    DECLARE_ID (reverbWidth)
    DECLARE_ID (delayFeedback)
    DECLARE_ID (delayCrossfeed)
    DECLARE_ID (delayMix)
    DECLARE_ID (delay)
    DECLARE_ID (legato)
    DECLARE_ID (voiceMode)
    DECLARE_ID (lfoWaveShape)
    DECLARE_ID (lfoRate)
    DECLARE_ID (lfoDepth)
    DECLARE_ID (lfoBeat)
    DECLARE_ID (lfoSync)
    DECLARE_ID (modAttack)
    DECLARE_ID (modDecay)
    DECLARE_ID (modSustain)
    DECLARE_ID (modRelease)
    DECLARE_ID (modParam)
    DECLARE_ID (modItem)
    DECLARE_ID (modDepth)
    DECLARE_ID (masterLevel)
    DECLARE_ID (chosusSpeed)
    DECLARE_ID (chorusDepth)
    DECLARE_ID (chrousWidth)
    DECLARE_ID (chorusMix)
    DECLARE_ID (ARRANGERTRACK)
    DECLARE_ID (ARRANGERCLIP)
    DECLARE_ID (apply)
    DECLARE_ID (oscType)
    DECLARE_ID (bandLimit)
    DECLARE_ID (irFileData)
    DECLARE_ID (normalise)
    DECLARE_ID (trimSilence)
    DECLARE_ID (preGain)
    DECLARE_ID (postGain)
    DECLARE_ID (highPassMidiNoteNumber)
    DECLARE_ID (lowPassMidiNoteNumber)

    #undef DECLARE_ID
}

} // namespace tracktion_engine
