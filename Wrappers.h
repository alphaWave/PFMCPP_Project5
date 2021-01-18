
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

