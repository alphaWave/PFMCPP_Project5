#include <iostream>
#include "EffectProcessor.h"


EffectProcessor::EffectProcessor() : lowpass(Filter(Filter::LP)), bandpass(Filter(Filter::BP)), highpass(Filter(Filter::HP))
{
}

EffectProcessor::~EffectProcessor()
{
    bandpass.filterLFO.rateInBPM = 135;
    bandpass.filterLFO.convertBPMToHz();
    bandpass.filterLFO.fadeInLFO(22050);
}

void EffectProcessor::printBPLFOrateInBPM()
{
    std::cout << "fx1's bandpass-LFO is set to " << this->bandpass.filterLFO.rateInBPM << "BPM" << std::endl;
}
