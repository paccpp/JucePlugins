/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AmplitudeModulationAudioProcessorEditor::AmplitudeModulationAudioProcessorEditor(AmplitudeModulationAudioProcessor& p) :
AudioProcessorEditor(&p),
m_processor(p),
m_freq_slider("frequency"),
m_freq_label("frequency_label", "Carrier")
{
    // configure slider
    m_freq_slider.setTextValueSuffix("Hz");
    m_freq_slider.setRange(0, 20, 0.01);
    
    // attach a listener to this component to be notified when the slider value changed.
    m_freq_slider.addListener(this);
    
    // add slider component as a child component of this one.
    addAndMakeVisible(m_freq_slider);
    
    m_freq_label.setColour(juce::Label::ColourIds::textColourId, Colours::whitesmoke);
    addAndMakeVisible(m_freq_label);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);
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
    
    juce::Rectangle<int> bounds = getLocalBounds();
    
    g.setColour(juce::Colours::black.withAlpha(0.6f));
    g.fillRect(bounds.removeFromTop(55));
}

void AmplitudeModulationAudioProcessorEditor::resized()
{
    juce::Rectangle<int> bounds = getLocalBounds().reduced(5);
    
    m_freq_label.setBounds(bounds.removeFromTop(20));
    m_freq_slider.setBounds(bounds.removeFromTop(30));
}
