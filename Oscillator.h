#pragma once

#include "LeakedObjectDetector.h"


struct Oscillator
{
    struct OscillatorType
    {
        enum Waveform {sine, triangle, pulse, whiteNoise, pinkNoise};

        Waveform waveform;
        float dutyCycle = 0.0f;
        int nrOfVoices = 1;
        float detune = 0.0f;
        int phase = 0;

        OscillatorType();
        OscillatorType(Waveform waveformToUse);
        ~OscillatorType();

        void cycleThroughNrOfVoices();
        int setNewPhase(int newPhase);
        bool changeWaveform(Waveform waveformToUse);

        JUCE_LEAK_DETECTOR(OscillatorType)
    };

    OscillatorType oscillatorType;
    int octave = 0;
    int semitones = 0;
    float coarse = 0;
    float fine = 0;
    float samplingFreq = 44100;
    GraphicalRepresentation oscRepresentation { GraphicalRepresentation::grey };

    Oscillator();
    Oscillator(OscillatorType oscillatorTypeToUse);
    ~Oscillator();

    void printFineTuning();
    void playSound();
    int convertOctavesToSemitones(int octaves);
    float setSamplingFrequency(float newSamplingFrequency);

    JUCE_LEAK_DETECTOR(Oscillator)
};
