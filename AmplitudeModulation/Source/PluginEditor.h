/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class AmplitudeModulationAudioProcessorEditor : public AudioProcessorEditor, public juce::Slider::Listener
{
public:
    AmplitudeModulationAudioProcessorEditor (AmplitudeModulationAudioProcessor&);
    ~AmplitudeModulationAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;

private:
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AmplitudeModulationAudioProcessor& m_processor;
    
    juce::Slider    m_freq_slider;
    juce::Label     m_freq_label;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmplitudeModulationAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
