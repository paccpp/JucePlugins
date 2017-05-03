/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "Osc.hpp"

//==============================================================================
/**
*/
class AmplitudeModulationAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AmplitudeModulationAudioProcessor();
    ~AmplitudeModulationAudioProcessor();
    
    void setFrequency(double new_freq);
    
    void setTremoloDepth(double new_depth);
    
    void setOutputGain(double new_gain);

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    
    paccpp::Osc<float> m_osc;
    
    juce::LinearSmoothedValue<float> m_depth;
    juce::LinearSmoothedValue<float> m_gain;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmplitudeModulationAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
