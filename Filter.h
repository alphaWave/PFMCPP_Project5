#pragma once

#include "LeakedObjectDetector.h"
#include "GraphicalRepresentation.h"


struct Filter
{
    struct FilterLFO
    {
        enum Waveform {sine, triangle, square};

        Waveform waveform;
        int rateInBPM;
        float rateInHz;
        float amplitude = 1;
        bool isBPM = true;

        FilterLFO();
        ~FilterLFO();

        void fadeInLFO(int howManySamples);
        float convertBPMToHz();
        Waveform getWaveform();

        JUCE_LEAK_DETECTOR(FilterLFO)
    };

    enum FilterType { LP, BP, HP };

    GraphicalRepresentation filterRepresentation = { GraphicalRepresentation::grey };
    float resonance = 0;
    float cutoff = 1000;
    unsigned int mix = 100;
    FilterType filterType;
    FilterLFO filterLFO;

    Filter(FilterType filterTypeToUse);
    ~Filter();

    void printPosition();
    unsigned int setMixValueToDefault();
    void sweepThroughFrequencyRange();
    float setResonance(float newResonance);

    JUCE_LEAK_DETECTOR(Filter)
};
