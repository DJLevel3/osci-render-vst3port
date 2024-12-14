#include "SosciPluginProcessor.h"
#include "SosciPluginEditor.h"
#include <juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h>

SosciPluginEditor::SosciPluginEditor(SosciAudioProcessor& p) : CommonPluginEditor(p, "sosci", "sosci"), audioProcessor(p) {
    initialiseMenuBar(model);
    resized();
}

void SosciPluginEditor::paint(juce::Graphics& g) {
    g.fillAll(Colours::veryDark);
}

void SosciPluginEditor::resized() {
    auto topBar = getLocalBounds().removeFromTop(25).removeFromLeft(200);
    menuBar.setBounds(topBar);
    auto visualiserArea = getLocalBounds();
    visualiserArea.removeFromTop(25);
    visualiser.setBounds(visualiserArea);
}
