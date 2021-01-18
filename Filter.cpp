#include <iostream>
#include "Filter.h"


Filter::FilterLFO::FilterLFO()
{
    waveform = sine;
    rateInBPM = 128;
    rateInHz = 100;
}

Filter::FilterLFO::~FilterLFO()
{
}

Filter::Filter(FilterType filterTypeToUse) : 
    filterType(filterTypeToUse)
{
}

Filter::~Filter()
{
}

void Filter::FilterLFO::fadeInLFO(int howManySamples)
{
    float fadeStep = amplitude / howManySamples;
    float targetAmplitude = amplitude;
    while (amplitude < targetAmplitude)
    {
        amplitude += fadeStep;
        if (amplitude > targetAmplitude)
        {
            amplitude = targetAmplitude;
        }
        std::cout << "Current Amplitude = " << amplitude << std::endl;
    }
    std::cout << "Reached target-Amplitude" << std::endl;
}

float Filter::FilterLFO::convertBPMToHz()
{
    std::cout << "Converting " << rateInBPM << " BPM to Hz..." << std::endl;
    rateInHz = rateInBPM / 60;
    isBPM = false;
    std::cout << "Rate in Hz = " << rateInHz << std::endl;
    return rateInHz;
}
Filter::FilterLFO::Waveform Filter::FilterLFO::getWaveform()
{
    return waveform;
}

void Filter::printPosition()
{
    std::cout << "LPF is at position (" << this->filterRepresentation.xCoordinate << ", " << this->filterRepresentation.yCoordinate << ")" << std::endl;
}

unsigned int Filter::setMixValueToDefault()
{
    mix = 100;
    return mix;
}

void Filter::sweepThroughFrequencyRange()
{
    std::cout << "Sweeping through frequency range..." << std::endl;
    for (int i = 0; i < 20001; ++i)
    {
        cutoff = i;
    }
}

float Filter::setResonance(float newResonance)
{
    resonance = newResonance;
    return resonance;
}
