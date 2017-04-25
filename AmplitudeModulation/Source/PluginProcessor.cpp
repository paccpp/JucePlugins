/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AmplitudeModulationAudioProcessor::AmplitudeModulationAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    m_osc.setFrequency(2);
}

AmplitudeModulationAudioProcessor::~AmplitudeModulationAudioProcessor()
{
}

void AmplitudeModulationAudioProcessor::setFrequency(double new_freq)
{
    m_osc.setFrequency(new_freq);
}

//==============================================================================
const String AmplitudeModulationAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AmplitudeModulationAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AmplitudeModulationAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double AmplitudeModulationAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AmplitudeModulationAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AmplitudeModulationAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AmplitudeModulationAudioProcessor::setCurrentProgram (int index)
{
}

const String AmplitudeModulationAudioProcessor::getProgramName (int index)
{
    return String();
}

void AmplitudeModulationAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AmplitudeModulationAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    m_osc.setSampleRate(sampleRate);
}

void AmplitudeModulationAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AmplitudeModulationAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AmplitudeModulationAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    //const int totalNumOutputChannels = getTotalNumOutputChannels();
    
    for(int i = 0; i < buffer.getNumSamples(); ++i)
    {
        float amp = m_osc.process();
        
        // This is the place where you'd normally do the guts of your plugin's
        // audio processing...
        for(int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            float* channelData = buffer.getWritePointer(channel);
            
            channelData[i] *= amp;
        }
    }
}

//==============================================================================
bool AmplitudeModulationAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AmplitudeModulationAudioProcessor::createEditor()
{
    return new AmplitudeModulationAudioProcessorEditor (*this);
}

//==============================================================================
void AmplitudeModulationAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AmplitudeModulationAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AmplitudeModulationAudioProcessor();
}
