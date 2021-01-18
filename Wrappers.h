#pragma once

#include "Oscillator.h"
#include "Filter.h"


struct GraphicalRepresentation;
struct OscillatorType;
struct FilterLFO;
struct Synthesizer;
struct EffectProcessor;

struct GraphicalRepresentationWrapper
{
    GraphicalRepresentationWrapper(GraphicalRepresentation* ptr);
    ~GraphicalRepresentationWrapper();

    GraphicalRepresentation* ptrToGraphRep = nullptr; 
};

struct OscillatorWrapper
{
    OscillatorWrapper(Oscillator* ptr);
    ~OscillatorWrapper();

    Oscillator* ptrToOscillator = nullptr;
};

struct OscillatorTypeWrapper
{
    OscillatorTypeWrapper(Oscillator::OscillatorType* ptr);
    ~OscillatorTypeWrapper();

    Oscillator::OscillatorType* ptrToOscillatorType = nullptr;
};

struct FilterWrapper
{
    FilterWrapper(Filter* ptr);
    ~FilterWrapper();

    Filter* ptrToFilter = nullptr;
};
    
struct FilterLFOWrapper
{
    FilterLFOWrapper(Filter::FilterLFO* ptr);
    ~FilterLFOWrapper();

    Filter::FilterLFO* ptrToFilterLFO = nullptr;
};

struct SynthesizerWrapper
{
    SynthesizerWrapper(Synthesizer* ptr);
    ~SynthesizerWrapper();

    Synthesizer* ptrToSynthesizer = nullptr;
};

struct EffectProcessorWrapper
{
    EffectProcessorWrapper(EffectProcessor* ptr);
    ~EffectProcessorWrapper();

    EffectProcessor* ptrToEffectProcessor = nullptr;
};
