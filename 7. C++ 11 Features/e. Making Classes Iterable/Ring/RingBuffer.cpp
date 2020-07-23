#include <iostream>
#include "Ring.h"

using namespace std;
using namespace justinlicari;

// In this example, we implement a range based loop.
// To do this, we'll implement a collection-type class. Specifically, we'll
// implement a ring buffer class. This is also known as a circular buffer or cycle
// buffer.

// A ring buffer is an area of memory you can write to. When you reach the end of it,
// it starts writing to the beginning. They are often used in multimedia applications, 
// since you can write to the buffer, and read a little bit ahead of it. When you run out of
// memory, instead of stopping, the read and write pointers cycle around the same portion 
// of memory.

int main() {

    // We want to pass 'ring' a template type, like 'string' for example.
    // When we instantiate our ringbuffer, we want to specify the size of memory
    // that it's using. Here, we'll pass a constructor argument '3' to indicate the
    // maximum number of strings in the buffer.
    Ring<string> textRing(3);

    // Since the buffer size is 3, we expect the "four" to overwrite the "one".
    textRing.add("one");
    textRing.add("two");
    textRing.add("three");
    textRing.add("four");

    // We'd like to be able to iterate through classes using range based loops,
    // like this. This requires our classes to be iterable 
    // (the C++ 98 syntax would involve creating an iterator, using textRing.begin()
    // and textRing.end()).
    for(auto value: textRing) {
        cout << value << endl;
    }

    // C++ 98 syntax
    for(Ring<string>::Iterator it=textRing.begin(); it != textRing.end(); it++) {
        cout << *it << endl;
    }

    // To do this, we'll need a begin() and end() method to return the values at
    // the start and end of the textRing, respectively. We'll also need to implement 
    // the '++' operator, the '*' dereference operator, and the '!=' operator.

    return 0;
}