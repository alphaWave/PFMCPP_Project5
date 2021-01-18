#pragma once


struct GraphicalRepresentation;
struct Oscillator;
//struct OscillatorType;
struct Filter;
//struct FilterLFO;
struct Synthesizer;
struct EffectProcessor;

struct GraphicalRepresentationWrapper
{
    GraphicalRepresentationWrapper(GraphicalRepresentation* ptr) : ptrToGraphRep(ptr) {}
    ~GraphicalRepresentationWrapper()
    {
        delete ptrToGraphRep;
        ptrToGraphRep = nullptr;
    }

    GraphicalRepresentation* ptrToGraphRep = nullptr; 
};

struct OscillatorWrapper
{
    OscillatorWrapper(Oscillator* ptr) : ptrToOscillator(ptr) {}
    ~OscillatorWrapper()
    {
        delete ptrToOscillator;
        ptrToOscillator = nullptr;
    }

    Oscillator* ptrToOscillator = nullptr;
};

struct OscillatorTypeWrapper
{
    OscillatorTypeWrapper(Oscillator::OscillatorType* ptr) : ptrToOscillatorType(ptr) {}
    ~OscillatorTypeWrapper()
    {
        delete ptrToOscillatorType;
        ptrToOscillatorType = nullptr;
    }

    Oscillator::OscillatorType* ptrToOscillatorType = nullptr;
};

struct FilterWrapper
{
    FilterWrapper(Filter* ptr) : ptrToFilter(ptr) {}
    ~FilterWrapper()
    {
        delete ptrToFilter;
        ptrToFilter = nullptr;
    }

    Filter* ptrToFilter = nullptr;
};
    
struct FilterLFOWrapper
{
    FilterLFOWrapper(Filter::FilterLFO* ptr) : ptrToFilterLFO(ptr) {}
    ~FilterLFOWrapper()
    {
        delete ptrToFilterLFO;
        ptrToFilterLFO = nullptr;
    }

    Filter::FilterLFO* ptrToFilterLFO = nullptr;
};

struct SynthesizerWrapper
{
    SynthesizerWrapper(Synthesizer* ptr) : ptrToSynthesizer(ptr) {}
    ~SynthesizerWrapper()
    {
        delete ptrToSynthesizer;
        ptrToSynthesizer = nullptr;
    }

    Synthesizer* ptrToSynthesizer = nullptr;
};

struct EffectProcessorWrapper
{
    EffectProcessorWrapper(EffectProcessor* ptr) : ptrToEffectProcessor(ptr) {}
    ~EffectProcessorWrapper()
    {
        delete ptrToEffectProcessor;
        ptrToEffectProcessor = nullptr;
    }

    EffectProcessor* ptrToEffectProcessor = nullptr;
};
