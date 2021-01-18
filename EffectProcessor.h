#pragma once

#include "LeakedObjectDetector.h"
#include "Filter.h"


 struct EffectProcessor
 {
     Filter lowpass, bandpass, highpass;

     EffectProcessor();
     ~EffectProcessor();

    void printBPLFOrateInBPM();

    JUCE_LEAK_DETECTOR(EffectProcessor)
 };
 