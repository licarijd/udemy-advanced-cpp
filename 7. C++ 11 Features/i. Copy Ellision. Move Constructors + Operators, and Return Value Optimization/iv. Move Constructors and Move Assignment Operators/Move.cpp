// The move constructor looks a lot like the copy constructor,
// except it uses r-value references.

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Test {

private:

    static const int SIZE=100;

    // We should always initialize to null as best practice;
    // The previous examples should have this as well.
    int *_pBuffer{nullptr};

public:

    Test() {
        _pBuffer = new int[SIZE]{};
    }

    Test(int i) {
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for (int i=0; i<SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other) {
        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    // The move constructor has to take a mutable r-value reference;
    // it can't be const since it needs to change "other".
    // So we're gonna get a temporary value, and the goal is we want to 
    // take some resources from it.
    Test(Test &&other) {

        // What we want to do is this:
        _pBuffer = other._pBuffer;

        // But there's a problem. The destructor for other will deallocate pBuffer
        // (see ~Test()). We've taken it in this move constructor, but it will
        // be deallocated.

        // So, after we take other's pBuffer, we set it to null so that 
        // it can't deallocate it itself:
        other._pBuffer = nullptr;

        // So unlike in the copy constructor, we don't need to allocate memory using memcpy.
    }

    // Assignment operator
    Test &operator=(const Test &other) {
        cout << "assignment" << endl;

                _pBuffer = new int[SIZE]{};

        // In this case, we need to allocate memory and copy the bytes from
        // the object who's data we're copying over. The first parameter
        // is the thing we're copying to, the thing we're copying from,
        // and the number of bytes we're copying.
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        
        return *this;
    }

    Test &operator=(Test &&other) {
        
        // This is a little more complicated than the move constructor, because this
        // object which we're assigning to will have already allocated memory.
        // So, we need to free up any memory that it's allocated.
        delete [] _pBuffer;

        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;

        return *this;
    }

    // Destructor
    ~Test() {
        cout << "destructor" << endl;

        // It's important to delete memory so that we don't get a memory leak.
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
};

int main() {

    // We'd expect this to run the assignment operator or copy constructor,
    // but it doesn't because of constructor ellision (r-value optimization).
    // Test test = getTest();

    // So what we want to do is construct the object and then assign it,
    // so we're sure we're getting some form of assignment operator.
    // Since we're passing an r-value, the program will invoke the move 
    // assignment operator.

    Test test;
    test = getTest();

    // ** Remember the rule of 3 - that if you're implementing an assignment 
    // operator, you need a copy contructor and destructor. Similarly now,
    // we want to implement the move assignment operator and move constructor
    // as well.

    // We can use "default" instead of all of these constructors if we only care 
    // about a shallow copy.

    return 0;
}