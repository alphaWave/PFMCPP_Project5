/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





#include <iostream>

/*
 UDT 1:
 */
struct GraphicalRepresentation
{
    enum Color {white, grey, black, blue};

    int xCoordinate = 0;
    int yCoordinate = 0;
    int width = 40;
    int height = 20;
    Color backgroundColor = black;
    bool drawRepresentation = false;
    string name = "";

    GraphicalRepresentation(int newXCoord, int newYCoord, int newWidth, int newHeight);
    GraphicalRepresentation(Color newBackgroundColor);
    ~GraphicalRepresentation();

    void printDimensions()
    {
        cout << "Your new Plugin has size " << this->width << " x " << this->height << "." << endl;
    }

    bool moveToXCoord(int newXCoord, int stepsize = 16);
    bool moveToYCoord(int newYCoord, int stepsize = 10);
    void attachLeftOf(GraphicalRepresentation targetRepresentation);
};

GraphicalRepresentation::GraphicalRepresentation(int newXCoord, int newYCoord, int newWidth, int newHeight) : xCoordinate(newXCoord), yCoordinate(newYCoord), width(newWidth), height(newHeight) {}
GraphicalRepresentation::GraphicalRepresentation(Color newBackgroundColor)
{
    backgroundColor = newBackgroundColor;
}
GraphicalRepresentation::~GraphicalRepresentation()
{
}

bool GraphicalRepresentation::moveToXCoord(int newXCoord, int stepsize)
{
    while (xCoordinate < newXCoord)
    {
        xCoordinate += stepsize;
        cout << "xCoordinate = " << xCoordinate << endl;
    }
    return true;
}
bool GraphicalRepresentation::moveToYCoord(int newYCoord, int stepsize)
{
    while (yCoordinate < newYCoord){
        yCoordinate += stepsize;
        cout << "yCoordinate = " << yCoordinate << endl;
    }
    return true;
}
void GraphicalRepresentation::attachLeftOf(GraphicalRepresentation targetRepresentation)
{
    xCoordinate = targetRepresentation.xCoordinate - width;
    yCoordinate = targetRepresentation.yCoordinate;
    cout << "New xCoordinate = " << xCoordinate << ", new yCoordinate = " << yCoordinate << endl;
}


/*
 UDT 2:
 */
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

        OscillatorType()
        {
            waveform = pulse;
            dutyCycle = 0.5f;
        }
        OscillatorType(Waveform waveformToUse) : waveform(waveformToUse) {}
        ~OscillatorType() {}

        void cycleThroughNrOfVoices();
        int setNewPhase(int newPhase);
        bool changeWaveform(Waveform waveformToUse);
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

    void printFineTuning()
    {
        cout << "pinkNoise's fine tuning is set to " << this->fine << endl;
    }

    void playSound();
    int convertOctavesToSemitones(int octaves);
    float setSamplingFrequency(float newSamplingFrequency);
};


void Oscillator::OscillatorType::cycleThroughNrOfVoices()
{
    for (int i = 1; i <= 16; ++i)
    {
        cout << "Number of voices = " << i << endl;
    }
}
int Oscillator::OscillatorType::setNewPhase(int newPhase)
{
    phase = newPhase;
    return phase;
}
bool Oscillator::OscillatorType::changeWaveform(Waveform waveformToUse){
    cout << "Changing Waveform..." << endl;
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
        cout << "Octaves-value out of range" << endl;
    }
    return semitones;
}
float Oscillator::setSamplingFrequency(float newSamplingFrequency)
{
    if (newSamplingFrequency >= 44100 && newSamplingFrequency <= 192000)
    {
        samplingFreq = newSamplingFrequency;
        cout << "Sampling-frequency set to " << samplingFreq << endl;
    }
    else
    {
        cout << "Sampling-frequency out of range" << endl;
    }
    return samplingFreq;
}


/*
 UDT 3:
 */
struct Filter
{
    struct FilterLFO
    {
        enum Waveform {sine, triangle, square};

        Waveform waveform;
        int rateInBPM;
        float rateInHz;
        float amplitude = 1;
        bool isBPM = true;

        FilterLFO() 
        {
            waveform = sine;
            rateInBPM = 128;
            rateInHz = 100;
        }
        ~FilterLFO() {}

        void fadeInLFO(int howManySamples);
        float convertBPMToHz();
        Waveform getWaveform();
    };

    enum FilterType { LP, BP, HP };

    GraphicalRepresentation filterRepresentation = { GraphicalRepresentation::grey };
    float resonance = 0;
    float cutoff = 1000;
    unsigned int mix = 100;
    FilterType filterType;
    FilterLFO filterLFO;

    Filter(FilterType filterTypeToUse);
    ~Filter();

    void printPosition()
    {
        cout << "LPF is at position (" << this->filterRepresentation.xCoordinate << ", " << this->filterRepresentation.yCoordinate << ")" << endl;
    }

    unsigned int setMixValueToDefault();
    void sweepThroughFrequencyRange();
    float setResonance(float newResonance);
};

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
        cout << "Current Amplitude = " << amplitude << endl;
    }
    cout << "Reached target-Amplitude" << endl;
}
float Filter::FilterLFO::convertBPMToHz()
{
    cout << "Converting " << rateInBPM << " BPM to Hz..." << endl;
    rateInHz = rateInBPM / 60;
    isBPM = false;
    cout << "Rate in Hz = " << rateInHz << endl;
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

unsigned int Filter::setMixValueToDefault()
{
    mix = 100;
    return mix;
}
void Filter::sweepThroughFrequencyRange()
{
    cout << "Sweeping through frequency range..." << endl;
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

/*
 new UDT 4:
 */
struct Synthesizer
{
    Oscillator sine, saw, square;
    Filter lowpass = Filter(Filter::LP);
    Filter highpass = Filter(Filter::HP);

    Synthesizer();
    ~Synthesizer();

    void printSinePhase()
    {
        cout << "New phase of synth1's sine-osc = " << this->sine.oscillatorType.phase << endl;
    }
};

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

/*
 new UDT 5:
 */
 struct EffectProcessor
 {
     Filter lowpass, bandpass, highpass;

     EffectProcessor();
     ~EffectProcessor();

    void printBPLFOrateInBPM()
    {
        cout << "fx1's bandpass-LFO is set to " << this->bandpass.filterLFO.rateInBPM << "BPM" << endl;
    }
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
    GraphicalRepresentation pluginFrame = GraphicalRepresentation(0, 0, 1600, 800);
    GraphicalRepresentation synthSection = GraphicalRepresentation(0, 0, 1600, 400);
    GraphicalRepresentation fxSection = GraphicalRepresentation(0, 400, 1600, 400);

    cout << "Your new Plugin has size " << pluginFrame.width << " x " << pluginFrame.height << "." << endl;
    pluginFrame.printDimensions();

    Oscillator pinkNoise = Oscillator(Oscillator::OscillatorType::pinkNoise);
    Oscillator whiteNoise = Oscillator(Oscillator::OscillatorType::whiteNoise);
    
    cout << "pinkNoise's fine tuning is set to " << pinkNoise.fine << endl;
    pinkNoise.printFineTuning();

    Filter lpf = Filter(Filter::LP);
    Filter hpf = Filter(Filter::HP);

    hpf.filterRepresentation.xCoordinate = 1000;
    hpf.filterRepresentation.yCoordinate = 600;
    lpf.filterRepresentation.backgroundColor = GraphicalRepresentation::black;
    lpf.filterRepresentation.attachLeftOf(hpf.filterRepresentation);

    cout << "LPF is at position (" << lpf.filterRepresentation.xCoordinate << ", " << lpf.filterRepresentation.yCoordinate << ")" << endl;
    lpf.printPosition();

    Synthesizer synth1;
    Synthesizer synth2;

    synth1.sine.oscillatorType.setNewPhase(90);
    cout << "New phase of synth1's sine-osc = " << synth1.sine.oscillatorType.phase << endl;
    synth1.printSinePhase();
    synth1.saw.setSamplingFrequency(1000000000);
    synth1.saw.setSamplingFrequency(192000);

    synth2.square.convertOctavesToSemitones(4);

    EffectProcessor fx1 = EffectProcessor();
    EffectProcessor fx2 = EffectProcessor();

    fx1.bandpass.resonance = 80.2f;
    fx2.bandpass.resonance = 40.4f;

    cout << "fx1's bandpass-LFO is set to " << fx1.bandpass.filterLFO.rateInBPM << "BPM" << endl;
    fx1.printBPLFOrateInBPM();

    std::cout << "good to go!" << std::endl;
}
