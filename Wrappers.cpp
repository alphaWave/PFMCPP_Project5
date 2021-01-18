#include "Wrappers.h"
#include "GraphicalRepresentation.h"
#include "Synthesizer.h"
#include "EffectProcessor.h"


GraphicalRepresentationWrapper::GraphicalRepresentationWrapper(GraphicalRepresentation* ptr) : 
    ptrToGraphRep(ptr)
{
}

GraphicalRepresentationWrapper::~GraphicalRepresentationWrapper()
{
    delete ptrToGraphRep;
    ptrToGraphRep = nullptr;
}

OscillatorWrapper::OscillatorWrapper(Oscillator* ptr) : 
    ptrToOscillator(ptr) 
{
}

OscillatorWrapper::~OscillatorWrapper()
{
    delete ptrToOscillator;
    ptrToOscillator = nullptr;
}

OscillatorTypeWrapper::OscillatorTypeWrapper(Oscillator::OscillatorType* ptr) : 
    ptrToOscillatorType(ptr)
{
}

OscillatorTypeWrapper::~OscillatorTypeWrapper()
{
    delete ptrToOscillatorType;
    ptrToOscillatorType = nullptr;
}

FilterWrapper::FilterWrapper(Filter* ptr) : 
    ptrToFilter(ptr)
{
}

FilterWrapper::~FilterWrapper()
{
    delete ptrToFilter;
    ptrToFilter = nullptr;
}

FilterLFOWrapper::FilterLFOWrapper(Filter::FilterLFO* ptr) : 
    ptrToFilterLFO(ptr)
{
}

FilterLFOWrapper::~FilterLFOWrapper()
{
    delete ptrToFilterLFO;
    ptrToFilterLFO = nullptr;
}

SynthesizerWrapper::SynthesizerWrapper(Synthesizer* ptr) : 
    ptrToSynthesizer(ptr)
{
}

SynthesizerWrapper::~SynthesizerWrapper()
{
    delete ptrToSynthesizer;
    ptrToSynthesizer = nullptr;
}

EffectProcessorWrapper::EffectProcessorWrapper(EffectProcessor* ptr) : 
    ptrToEffectProcessor(ptr)
{
}

EffectProcessorWrapper::~EffectProcessorWrapper()
{
    delete ptrToEffectProcessor;
    ptrToEffectProcessor = nullptr;
}
