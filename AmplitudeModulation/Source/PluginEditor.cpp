/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AmplitudeModulationAudioProcessorEditor::AmplitudeModulationAudioProcessorEditor (AmplitudeModulationAudioProcessor& p)
    : AudioProcessorEditor (&p), m_processor(p), m_freq_slider("frequency")
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(m_freq_slider);
    
    m_freq_slider.setRange(0, 200);
    m_freq_slider.addListener(this);
}

AmplitudeModulationAudioProcessorEditor::~AmplitudeModulationAudioProcessorEditor()
{
    m_freq_slider.removeListener(this);
}

//==============================================================================
void AmplitudeModulationAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if(slider == &m_freq_slider)
    {
        double freq = slider->getValue();
        m_processor.setFrequency(freq);
    }
}

//==============================================================================
void AmplitudeModulationAudioProcessorEditor::paint(Graphics& g)
{
    g.fillAll(Colours::whitesmoke);
}

void AmplitudeModulationAudioProcessorEditor::resized()
{
    m_freq_slider.setSize(getWidth(), 50);
}
