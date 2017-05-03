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
m_freq_label("frequency_label", "Carrier Frequency"),
m_depth_slider("depth"),
m_depth_label("depth_label", "Tremolo Depth"),
m_gain_slider("gain"),
m_gain_label("gain_label", "Output Gain")
{
    const juce::Colour text_color(Colours::whitesmoke);
    
    // configure carrier frequency slider
    m_freq_slider.setTextValueSuffix("Hz");
    m_freq_slider.setRange(0, 20, 0.01);
    
    // attach a listener to this component to be notified when the slider value changed.
    m_freq_slider.addListener(this);
    
    // add slider component as a child component of this one.
    addAndMakeVisible(m_freq_slider);
    
    m_freq_label.setColour(juce::Label::ColourIds::textColourId, text_color);
    addAndMakeVisible(m_freq_label);
    
    // configure depth slider
    m_depth_slider.setRange(0., 1., 0.01);
    m_depth_slider.addListener(this);
    addAndMakeVisible(m_depth_slider);
    
    m_depth_label.setColour(juce::Label::ColourIds::textColourId, text_color);
    addAndMakeVisible(m_depth_label);
    
    // configure depth slider
    m_gain_slider.setRange(0., 1., 0.01);
    m_gain_slider.addListener(this);
    addAndMakeVisible(m_gain_slider);
    
    m_gain_label.setColour(juce::Label::ColourIds::textColourId, text_color);
    addAndMakeVisible(m_gain_label);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);
    
    m_freq_slider.setValue(2.);
    m_depth_slider.setValue(0.25);
    m_gain_slider.setValue(0.8);
}

AmplitudeModulationAudioProcessorEditor::~AmplitudeModulationAudioProcessorEditor()
{
    m_freq_slider.removeListener(this);
    m_depth_slider.removeListener(this);
    m_gain_slider.removeListener(this);
}

//==============================================================================
void AmplitudeModulationAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if(slider == &m_freq_slider)
    {
        double freq = slider->getValue();
        m_processor.setFrequency(freq);
    }
    else if(slider == &m_depth_slider)
    {
        double depth = slider->getValue();
        m_processor.setTremoloDepth(depth);
    }
    else if(slider == &m_gain_slider)
    {
        double gain = slider->getValue();
        m_processor.setOutputGain(gain);
    }
}

//==============================================================================
void AmplitudeModulationAudioProcessorEditor::paint(Graphics& g)
{
    g.fillAll(Colours::whitesmoke);
    
    juce::Rectangle<int> bounds = getLocalBounds();
    
    g.setColour(juce::Colours::black.withAlpha(0.6f));
    g.fillRect(bounds.removeFromTop(55));
    
    g.setColour(juce::Colours::black.withAlpha(0.4f));
    g.fillRect(bounds.removeFromTop(50));
    
    g.setColour(juce::Colours::black.withAlpha(0.6f));
    g.fillRect(bounds.removeFromTop(50));
}

void AmplitudeModulationAudioProcessorEditor::resized()
{
    juce::Rectangle<int> bounds = getLocalBounds().reduced(5);
    
    m_freq_label.setBounds(bounds.removeFromTop(20));
    m_freq_slider.setBounds(bounds.removeFromTop(30));
    
    m_depth_label.setBounds(bounds.removeFromTop(20));
    m_depth_slider.setBounds(bounds.removeFromTop(30));
    
    m_gain_label.setBounds(bounds.removeFromTop(20));
    m_gain_slider.setBounds(bounds.removeFromTop(30));
}
