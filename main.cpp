/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



#include <iostream>
#include "LeakedObjectDetector.h"

/*
 UDT 1:
 */


GraphicalRepresentation::GraphicalRepresentation(int newXCoord, int newYCoord, int newWidth, int newHeight) : xCoordinate(newXCoord), yCoordinate(newYCoord), width(newWidth), height(newHeight) {}
GraphicalRepresentation::GraphicalRepresentation(Color newBackgroundColor)
{
    backgroundColor = newBackgroundColor;
}
GraphicalRepresentation::~GraphicalRepresentation()
{
}

void GraphicalRepresentation::printDimensions()
{
    std::cout << "Your new Plugin has size " << this->width << " x " << this->height << "." << std::endl;
}
bool GraphicalRepresentation::moveToXCoord(int newXCoord, int stepsize)
{
    while (xCoordinate < newXCoord)
    {
        xCoordinate += stepsize;
        std::cout << "xCoordinate = " << xCoordinate << std::endl;
    }
    return true;
}
bool GraphicalRepresentation::moveToYCoord(int newYCoord, int stepsize)
{
    while (yCoordinate < newYCoord){
        yCoordinate += stepsize;
        std::cout << "yCoordinate = " << yCoordinate << std::endl;
    }
    return true;
}
void GraphicalRepresentation::attachLeftOf(GraphicalRepresentation targetRepresentation)
{
    xCoordinate = targetRepresentation.xCoordinate - width;
    yCoordinate = targetRepresentation.yCoordinate;
    std::cout << "New xCoordinate = " << xCoordinate << ", new yCoordinate = " << yCoordinate << std::endl;
}

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


/*
 UDT 2:
 */



void Oscillator::OscillatorType::cycleThroughNrOfVoices()
{
    for (int i = 1; i <= 16; ++i)
    {
        std::cout << "Number of voices = " << i << std::endl;
    }
}
int Oscillator::OscillatorType::setNewPhase(int newPhase)
{
    phase = newPhase;
    return phase;
}
bool Oscillator::OscillatorType::changeWaveform(Waveform waveformToUse){
    std::cout << "Changing Waveform..." << std::endl;
    waveform = waveformToUse;
    return true;
}

Oscillator::Oscillator() : oscillatorType(OscillatorType()) {}
Oscillator::Oscillator(OscillatorType oscillatorTypeToUse)
{
    oscillatorType = oscillatorTypeToUse;
}
Oscillator::~Oscillator()
{
}

void Oscillator::printFineTuning()
{
    std::cout << "Fine tuning is set to " << this->fine << std::endl;
}
void Oscillator::playSound()
{
    for (int i = 0; i < samplingFreq; ++i)
    {
        if (octave > -1 && octave < 6)
        {
            // plays the current sample; (putting this into a cout-statement seemed a bit too enthusiastic)
        }
    }
}
int Oscillator::convertOctavesToSemitones(int octaves)
{
    if (octaves > 0 && octaves < 5)
    {
        semitones = octaves * 12;
    }
    else
    {
        std::cout << "Octaves-value out of range" << std::endl;
    }
    return semitones;
}
float Oscillator::setSamplingFrequency(float newSamplingFrequency)
{
    if (newSamplingFrequency >= 44100 && newSamplingFrequency <= 192000)
    {
        samplingFreq = newSamplingFrequency;
        std::cout << "Sampling-frequency set to " << samplingFreq << std::endl;
    }
    else
    {
        std::cout << "Sampling-frequency out of range" << std::endl;
    }
    return samplingFreq;
}

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


/*
 UDT 3:
 */


void Filter::FilterLFO::fadeInLFO(int howManySamples)
{
    float fadeStep = amplitude / howManySamples;
    float targetAmplitude = amplitude;
    while (amplitude < targetAmplitude)
    {
        amplitude += fadeStep;
        if (amplitude > targetAmplitude)
        {
            amplitude = targetAmplitude;
        }
        std::cout << "Current Amplitude = " << amplitude << std::endl;
    }
    std::cout << "Reached target-Amplitude" << std::endl;
}
float Filter::FilterLFO::convertBPMToHz()
{
    std::cout << "Converting " << rateInBPM << " BPM to Hz..." << std::endl;
    rateInHz = rateInBPM / 60;
    isBPM = false;
    std::cout << "Rate in Hz = " << rateInHz << std::endl;
    return rateInHz;
}
Filter::FilterLFO::Waveform Filter::FilterLFO::getWaveform()
{
    return waveform;
}

Filter::Filter(FilterType filterTypeToUse) : filterType(filterTypeToUse) {}
Filter::~Filter()
{
}

void Filter::printPosition()
{
    std::cout << "LPF is at position (" << this->filterRepresentation.xCoordinate << ", " << this->filterRepresentation.yCoordinate << ")" << std::endl;
}
unsigned int Filter::setMixValueToDefault()
{
    mix = 100;
    return mix;
}
void Filter::sweepThroughFrequencyRange()
{
    std::cout << "Sweeping through frequency range..." << std::endl;
    for (int i = 0; i < 20001; ++i)
    {
        cutoff = i;
    }
}
float Filter::setResonance(float newResonance)
{
    resonance = newResonance;
    return resonance;
}

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

/*
 new UDT 4:
 */


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

/*
 new UDT 5:
 */
 struct EffectProcessor
 {
     Filter lowpass, bandpass, highpass;

     EffectProcessor();
     ~EffectProcessor();

    void printBPLFOrateInBPM();

    JUCE_LEAK_DETECTOR(EffectProcessor)
 };

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


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

int main()
{
    GraphicalRepresentationWrapper pluginFrame(new GraphicalRepresentation(0, 0, 1600, 800));
    GraphicalRepresentationWrapper synthSection(new GraphicalRepresentation(0, 0, 1600, 400));
    GraphicalRepresentationWrapper fxSection(new GraphicalRepresentation(0, 400, 1600, 400));

    std::cout << "Your new Plugin has size " << pluginFrame.ptrToGraphRep->width << " x " << pluginFrame.ptrToGraphRep->height << "." << std::endl;
    pluginFrame.ptrToGraphRep->printDimensions();

    OscillatorWrapper pinkNoise(new Oscillator(Oscillator::OscillatorType::pinkNoise));
    OscillatorWrapper whiteNoise(new Oscillator(Oscillator::OscillatorType::whiteNoise));
    
    std::cout << "pinkNoise's fine tuning is set to " << pinkNoise.ptrToOscillator->fine << std::endl;
    pinkNoise.ptrToOscillator->printFineTuning();

    FilterWrapper lpf(new Filter(Filter::LP));
    FilterWrapper hpf(new Filter(Filter::HP));

    hpf.ptrToFilter->filterRepresentation.xCoordinate = 1000;
    hpf.ptrToFilter->filterRepresentation.yCoordinate = 600;
    lpf.ptrToFilter->filterRepresentation.backgroundColor = GraphicalRepresentation::black;
    lpf.ptrToFilter->filterRepresentation.attachLeftOf(hpf.ptrToFilter->filterRepresentation);

    std::cout << "LPF is at position (" << lpf.ptrToFilter->filterRepresentation.xCoordinate << ", " << lpf.ptrToFilter->filterRepresentation.yCoordinate << ")" << std::endl;
    lpf.ptrToFilter->printPosition();

    SynthesizerWrapper synth1(new Synthesizer());
    SynthesizerWrapper synth2(new Synthesizer());

    synth1.ptrToSynthesizer->sine.oscillatorType.setNewPhase(90);
    std::cout << "New phase of synth1's sine-osc = " << synth1.ptrToSynthesizer->sine.oscillatorType.phase << std::endl;
    synth1.ptrToSynthesizer->printSinePhase();
    synth1.ptrToSynthesizer->saw.setSamplingFrequency(1000000000);
    synth1.ptrToSynthesizer->saw.setSamplingFrequency(192000);

    synth2.ptrToSynthesizer->square.convertOctavesToSemitones(4);

    EffectProcessorWrapper fx1(new EffectProcessor());
    EffectProcessorWrapper fx2(new EffectProcessor());

    fx1.ptrToEffectProcessor->bandpass.resonance = 80.2f;
    fx2.ptrToEffectProcessor->bandpass.resonance = 40.4f;

    std::cout << "fx1's bandpass-LFO is set to " << fx1.ptrToEffectProcessor->bandpass.filterLFO.rateInBPM << "BPM" << std::endl;
    fx1.ptrToEffectProcessor->printBPLFOrateInBPM();

    std::cout << "good to go!" << std::endl;
}
