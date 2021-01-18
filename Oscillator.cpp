#include <iostream>
#include "Oscillator.h"


Oscillator::OscillatorType::OscillatorType()
{
    waveform = pulse;
    dutyCycle = 0.5f;
}

Oscillator::OscillatorType::OscillatorType(Waveform waveformToUse) : 
    waveform(waveformToUse)
{
}

Oscillator::OscillatorType::~OscillatorType()
{
}

Oscillator::Oscillator() : oscillatorType(OscillatorType())
{
}

Oscillator::Oscillator(OscillatorType oscillatorTypeToUse)
{
    oscillatorType = oscillatorTypeToUse;
}

Oscillator::~Oscillator()
{
}

void Oscillator::OscillatorType::cycleThroughNrOfVoices()
{
    for (int i = 1; i <= 16; ++i)
    {
        std::cout << "Number of voices = " << i << std::endl;
    }
}

int Oscillator::OscillatorType::setNewPhase(int newPhase)
{
    phase = newPhase;
    return phase;
}

bool Oscillator::OscillatorType::changeWaveform(Waveform waveformToUse){
    std::cout << "Changing Waveform..." << std::endl;
    waveform = waveformToUse;
    return true;
}

void Oscillator::printFineTuning()
{
    std::cout << "Fine tuning is set to " << this->fine << std::endl;
}

void Oscillator::playSound()
{
    for (int i = 0; i < samplingFreq; ++i)
    {
        if (octave > -1 && octave < 6)
        {
            // plays the current sample; (putting this into a cout-statement seemed a bit too enthusiastic)
        }
    }
}

int Oscillator::convertOctavesToSemitones(int octaves)
{
    if (octaves > 0 && octaves < 5)
    {
        semitones = octaves * 12;
    }
    else
    {
        std::cout << "Octaves-value out of range" << std::endl;
    }
    return semitones;
}

float Oscillator::setSamplingFrequency(float newSamplingFrequency)
{
    if (newSamplingFrequency >= 44100 && newSamplingFrequency <= 192000)
    {
        samplingFreq = newSamplingFrequency;
        std::cout << "Sampling-frequency set to " << samplingFreq << std::endl;
    }
    else
    {
        std::cout << "Sampling-frequency out of range" << std::endl;
    }
    return samplingFreq;
}
