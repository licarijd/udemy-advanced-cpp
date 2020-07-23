#include <iostream>
using namespace std;

class MusicalInstrument {
public:
    void play(){
        cout << "Playing instrument" << endl;
    }
    void reset(){
        cout << "Resetting instrument" << endl;
    }
    virtual ~MusicalInstrument(){};
};

class Machine {
public:
    void start(){
        cout << "Starting machine" << endl;
    }
    void reset(){
        cout << "Resetting machine" << endl;
    }
    virtual ~Machine(){};
};

// A synthesizer is both a machine and a musical instrument, so we can make it inherit
// from both classes.
class Synthesizer: public Machine, public MusicalInstrument {
public:
    virtual ~Synthesizer(){};
};

int main() {
    
    Synthesizer *pSynth = new Synthesizer();

    // We can now call methods from either superclass.
    pSynth -> play();
    pSynth -> start();

    // The problem is what to do when the same method name and signature 
    // exists in more than one superclass (eg. the 'reset' method in this
    // example).
    // Oviously, this doesn't work.
    // pSynth -> reset();

    // We have to specify which implementation we want to use due to this 
    // ambiguity.
    // This requires the users of the synthesizer class to know 
    // implementaion details of the superclasses of synthesizer,
    // which is bad practice.
    pSynth -> Machine::reset();

    delete pSynth;

    return 0;
}

/* The Diamond Problem: 

You try doing multiple inheritance from classes which share a base class
somewhere down the line.

Any methods that exist in that base class would then be inherited by the subclasses,
even though the subclasses are inheriting from classes which already inherit from the
base class. This creates ambiguity.

*/

// In general, it's best to avoid mulitple inheritance. If it is used,
// make sure that the superclasses don't have methods with the same 
// signature.
