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

class IconProG2  : public MackieMCU
{
public:
    IconProG2 (ExternalControllerManager&);
    ~IconProG2();

    void acceptMidiMessage (int deviceIdx, const juce::MidiMessage&) override;
    
    void loopOnOffChanged (bool isLoopOn) override;
    void punchOnOffChanged (bool isPunching) override;
    void clickOnOffChanged (bool isClickOn) override;
    void snapOnOffChanged (bool isSnapOn) override;
    void slaveOnOffChanged (bool isSlaving) override;
    void undoStatusChanged (bool undo, bool redo) override;
    void automationReadModeChanged (bool isReading) override;
    void automationWriteModeChanged (bool isWriting) override;
    void setAssignmentMode (AssignmentMode newMode) override;
};

} // namespace tracktion_engine
