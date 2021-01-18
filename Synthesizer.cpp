#include <iostream>
#include "Synthesizer.h"

Synthesizer::Synthesizer()
{
    sine = Oscillator(sine);
    saw = Oscillator(saw);
    square = Oscillator();
}
Synthesizer::~Synthesizer()
{
    sine.oscillatorType.changeWaveform(Oscillator::OscillatorType::whiteNoise);
    lowpass.sweepThroughFrequencyRange();
}

void Synthesizer::printSinePhase()
{
    std::cout << "Phase of sine-osc = " << this->sine.oscillatorType.phase << std::endl;
}
