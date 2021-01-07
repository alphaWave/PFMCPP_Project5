/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
Since you didn't do Project 3:
write 3 UDTs below (where it asks for Copied UDTs) that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables

 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED

 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */

 #include <iostream>
 using namespace std;

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
    cout << "GraphicalRepresentation-Dtor" << endl;
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

        Waveform mWaveform;
        float dutyCycle = 0.0f;
        int nrOfVoices = 1;
        float detune = 0.0f;
        int phase = 0;

        OscillatorType()
        {
            mWaveform = pulse;
            dutyCycle = 0.5f;
        }
        OscillatorType(Waveform pWaveform) : mWaveform(pWaveform) {}
        ~OscillatorType() { cout << "OscillatorType-Dtor" << endl; }

        void cycleThroughNrOfVoices();
        int setNewPhase(int newPhase);
        bool changeWaveform(Waveform pWaveform);
    };

    OscillatorType mOscillatorType;
    int octave = 0;
    int semitones = 0;
    float coarse = 0;
    float fine = 0;
    float samplingFreq = 44100;
    GraphicalRepresentation oscRepresentation { GraphicalRepresentation::grey };

    Oscillator();
    Oscillator(OscillatorType pOscillatorType);
    ~Oscillator();
    
    void playSound(bool MIDISignal);
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
bool Oscillator::OscillatorType::changeWaveform(Waveform pWaveform){
    cout << "Changing Waveform..." << endl;
    return true;
}

Oscillator::Oscillator() : mOscillatorType(OscillatorType()) {}
Oscillator::Oscillator(OscillatorType pOscillatorType)
{
    mOscillatorType = OscillatorType(pOscillatorType);
}
Oscillator::~Oscillator()
{
    cout << "Oscillator-Dtor" << endl;
}

void Oscillator::playSound(bool MIDISignal)
{
    while (MIDISignal)
    {
        for (int i = 0; i < samplingFreq; ++i)
        {
            if (octave > -1 && octave < 6)
            {
                // plays the current sample; (putting this into a cout-statement seemed a bit too enthusiastic)
            }
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

        Waveform mWaveform;
        int rateInBPM;
        float rateInHz;
        float amplitude = 1;
        bool isBPM = true;

        FilterLFO() 
        {
            mWaveform = sine;
            rateInBPM = 128;
            rateInHz = 100;
        }
        ~FilterLFO() { cout << "FilterLFO-Dtor" << endl; }

        void fadeInLFO(int howManySamples);
        float convertBPMToHz();
        Waveform getWaveform();
    };

    enum FilterType { LP, BP, HP };

    GraphicalRepresentation filterRepresentation = { GraphicalRepresentation::grey };
    float resonance = 0;
    float cutoff = 1000;
    unsigned int mix = 100;
    FilterType mFilterType;
    FilterLFO mFilterLFO;

    Filter(FilterType pFilterType);
    ~Filter();

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
    return mWaveform;
}

Filter::Filter(FilterType pFilterType) : mFilterType(pFilterType) {}
Filter::~Filter()
{
    cout << "Filter-Dtor" << endl;
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
};

Synthesizer::Synthesizer()
{
    sine = Oscillator(sine);
    saw = Oscillator(saw);
    square = Oscillator();
}
Synthesizer::~Synthesizer()
{
    cout << "Synthesizer-Dtor" << endl;
    sine.mOscillatorType.changeWaveform(Oscillator::OscillatorType::whiteNoise);
    lowpass.sweepThroughFrequencyRange();
    cout << "Synthesizer destroyed" << endl;
}

/*
 new UDT 5:
 */
 struct EffectProcessor
 {
     Filter lowpass, bandpass, highpass;

     EffectProcessor();
     ~EffectProcessor();
 };

 EffectProcessor::EffectProcessor() : lowpass(Filter(Filter::LP)), bandpass(Filter(Filter::BP)), highpass(Filter(Filter::HP))
 {
 }
EffectProcessor::~EffectProcessor()
{
    cout << "EffectProcessor-Dtor" << endl;
    bandpass.mFilterLFO.rateInBPM = 135;
    bandpass.mFilterLFO.convertBPMToHz();
    bandpass.mFilterLFO.fadeInLFO(22050);
    cout << "Filter destroyed" << endl;
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

#include <iostream>
int main()
{
    GraphicalRepresentation pluginFrame = GraphicalRepresentation(0, 0, 1600, 800);
    GraphicalRepresentation synthSection = GraphicalRepresentation(0, 0, 1600, 400);
    GraphicalRepresentation fxSection = GraphicalRepresentation(0, 400, 1600, 400);

    cout << "Your new Plugin has size " << pluginFrame.width << " x " << pluginFrame.height << "." << endl;

    Oscillator pinkNoise = Oscillator(Oscillator::OscillatorType::pinkNoise);
    Oscillator whiteNoise = Oscillator(Oscillator::OscillatorType::whiteNoise);
    
    cout << "pinkNoise's fine tuning is set to " << pinkNoise.fine << endl;

    Filter lpf = Filter(Filter::LP);
    Filter hpf = Filter(Filter::HP);

    hpf.filterRepresentation.xCoordinate = 1000;
    hpf.filterRepresentation.yCoordinate = 600;
    lpf.filterRepresentation.backgroundColor = GraphicalRepresentation::black;
    lpf.filterRepresentation.attachLeftOf(hpf.filterRepresentation);

    cout << "LPF is at position (" << lpf.filterRepresentation.xCoordinate << ", " << lpf.filterRepresentation.yCoordinate << ")" << endl;

    Synthesizer synth1;
    Synthesizer synth2;

    synth1.sine.mOscillatorType.setNewPhase(90);
    cout << "New phase of synth1's sine-osc = " << synth1.sine.mOscillatorType.phase << endl;
    synth1.saw.setSamplingFrequency(1000000000);
    synth1.saw.setSamplingFrequency(192000);

    synth2.square.convertOctavesToSemitones(4);

    EffectProcessor fx1 = EffectProcessor();
    EffectProcessor fx2 = EffectProcessor();

    fx1.bandpass.resonance = 80.2f;
    fx2.bandpass.resonance = 40.4f;

    cout << "fx1's bandpass-LFO is set to " << fx1.bandpass.mFilterLFO.rateInBPM << "BPM" << endl;

    std::cout << "good to go!" << std::endl;
}
