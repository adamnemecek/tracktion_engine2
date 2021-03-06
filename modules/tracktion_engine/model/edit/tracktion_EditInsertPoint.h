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

/** */
class EditInsertPoint
{
public:
    EditInsertPoint (Edit&);
    virtual ~EditInsertPoint() = default;

    void setNextInsertPoint (double time, const juce::ReferenceCountedObjectPtr<Track>&);
    void setNextInsertPoint (double time);
    void setNextInsertPointAfterSelected();
    void lockInsertPoint (bool lock) noexcept;

    virtual void chooseInsertPoint (juce::ReferenceCountedObjectPtr<Track>&,
                                    double& start, bool pasteAfterSelection, SelectionManager*);

    void chooseInsertPoint (juce::ReferenceCountedObjectPtr<Track>&,
                            double& start, bool pasteAfterSelection, SelectionManager*,
                            std::function<bool (Track&)> allowedTrackPredicate);

protected:
    Edit& edit;
    double nextInsertPointTime = 0;
    EditItemID nextInsertPointTrack;
    int lockInsertPointCount = 0;
    bool nextInsertIsAfterSelected = false;
};

} // namespace tracktion_engine
