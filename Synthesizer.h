#pragma once

#include "LeakedObjectDetector.h"

struct Synthesizer
{
    Oscillator sine, saw, square;
    Filter lowpass = Filter(Filter::LP);
    Filter highpass = Filter(Filter::HP);

    Synthesizer();
    ~Synthesizer();

    void printSinePhase();

    JUCE_LEAK_DETECTOR(Synthesizer)
};
