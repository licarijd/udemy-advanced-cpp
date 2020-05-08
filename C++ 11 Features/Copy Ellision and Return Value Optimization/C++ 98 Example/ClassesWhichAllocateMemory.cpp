#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

class Test {

private:

    static const int SIZE=100;
    int *_pBuffer;

public:

    // Default constructor
    Test() {
        cout << "constructor" << endl;

        _pBuffer = new int[SIZE];

        // Oftentimes when allocating memory, we'll want to set all bytes (not elements)
        // of the buffer to zero. This can help reduce bugs since you know they
        // should be zero until you write to them.

        // One way to do this is with memset (can usually be found in
        // memory.h). It takes a buffer, and the value we want to set all bytes
        // in the buffer to (not the "ints" the bytes), and the number of bytes
        // that is in the buffer in total.

        // So if we set all 4 bytes of an int to zero, then the result is a 
        // bunch of ints with value 0.
        // memset(_pBuffer, 0, sizeof(int)*SIZE);

        // Many say that using memset is prone to error - we could overwrite the
        // end of the buffer by mistake.

        // Another way to do this which works if you're allocating a bunch of
        // primitives (like ints).

        _pBuffer = new int[SIZE]{};

        // This will zero all the bytes in the buffer.
    }

    // One parameter constructor
    Test(int i) {
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        // In C++ 98 we can't call one method from another, so it's common to 
        // have an init method, which multiple constructors can call.

        for (int i=0; i<SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    // Copy constructor
    Test(const Test &other) {
        cout << "copy constructor" << endl;

        _pBuffer = new int[SIZE]{};

        // In this case, we need to allocate memory and copy the bytes from
        // the object who's data we're copying over. The first parameter
        // is the thing we're copying to, the thing we're copying from,
        // and the number of bytes we're copying.
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
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

    Test test1 = getTest();
    cout << test1 << endl;

    return 0;
}