#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class OscirenderAudioProcessorEditor;
class LineArtComponent : public juce::GroupComponent, public juce::MouseListener {
public:
    LineArtComponent(OscirenderAudioProcessor&, OscirenderAudioProcessorEditor&);

    void resized() override;
    void update();
private:
    OscirenderAudioProcessor& audioProcessor;
    OscirenderAudioProcessorEditor& pluginEditor;

    juce::ToggleButton animate{"Animate"};
    juce::ToggleButton sync{"MIDI Sync"};
    juce::Label rateLabel{ "Framerate","Framerate"};
    juce::TextEditor rate;
    juce::Label offsetLabel{ "Offset","Offset" };
    juce::TextEditor offset;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LineArtComponent)
};