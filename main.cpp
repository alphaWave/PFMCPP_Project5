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


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */


#include <iostream>
#include "LeakedObjectDetector.h"
#include "EffectProcessor.h"
#include "Filter.h"
#include "GraphicalRepresentation.h"
#include "Oscillator.h"
#include "Synthesizer.h"
#include "Wrappers.h"


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
