/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
        ~OscillatorType() { cout << "OscillatorType-Dtor" << endl; }

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
    cout << "Oscillator-Dtor" << endl;
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
    FilterType filterType;
    FilterLFO filterLFO;

    Filter(FilterType filterTypeToUse);
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
    return waveform;
}

Filter::Filter(FilterType filterTypeToUse) : filterType(filterTypeToUse) {}
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
    sine.oscillatorType.changeWaveform(Oscillator::OscillatorType::whiteNoise);
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
    bandpass.filterLFO.rateInBPM = 135;
    bandpass.filterLFO.convertBPMToHz();
    bandpass.filterLFO.fadeInLFO(22050);
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

    synth1.sine.oscillatorType.setNewPhase(90);
    cout << "New phase of synth1's sine-osc = " << synth1.sine.oscillatorType.phase << endl;
    synth1.saw.setSamplingFrequency(1000000000);
    synth1.saw.setSamplingFrequency(192000);

    synth2.square.convertOctavesToSemitones(4);

    EffectProcessor fx1 = EffectProcessor();
    EffectProcessor fx2 = EffectProcessor();

    fx1.bandpass.resonance = 80.2f;
    fx2.bandpass.resonance = 40.4f;

    cout << "fx1's bandpass-LFO is set to " << fx1.bandpass.filterLFO.rateInBPM << "BPM" << endl;

    std::cout << "good to go!" << std::endl;
}
