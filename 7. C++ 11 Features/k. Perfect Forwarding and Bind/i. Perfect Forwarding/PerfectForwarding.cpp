#include <iostream>
using namespace std;

class Test {

};

// Example of a template declaration which uses r-values
// The idea behind perfect forwarding is that you might want to call the 
// right version of a function, depending on whether it passed an l-value or 
// r-value to our template function.

// As we saw in the example inside of main(), even though we use r-value notation
// ('&&'), it can be either an l-value or an r-value. Because we're going to end up with a 
// type T being inferred.

// And then, we might want to pass on the argument in such a way that it's r-value or l-value 
// characteristic is preserved, and we can do that with perfect forwarding.
template<typename T>
void call(T &&arg) {

    // We check if the type is an l-value or r-value reference

    // We can't do this, since the address of 'arg' will be an l-value.
    // so the l-value version is what will always be used.
    // check(arg);

    // So to solve this, we can use a static cast
    check(static_cast<T>(arg));

    // Now that we're making use of the inferred type that was called, 
    // we will get r-values if we pass an r-value.

    // If we pass an l-value and get "T reference", then the references collapse 
    // and the l-value function will be called.

    // There's a function called 'forward' which makes the above static_cast
    // solution a little simpler. It does the same thing, but is intended for this
    // particular situation.

    check(forward<T>(arg));
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}

int main() {

    // l-value reference
    Test test;

    // This compiles, even though 'test' is an l-value reference.
    // Usually, '&&' denotes an r-value reference.
    // 't' can't be an r-value reference because it can't bind to an r-value.
    // There's a rule in C++ 11 that if the 'auto' boiled down to an l-value 
    // reference type, then the references as a whole would collapse, and what we'd 
    // be left with is a l-value reference, which is why we can bind to an l-value.
    // This is called reference collapsing.
    auto &&t = test;

    call(Test());

    // You are very unlikely to use this!

    return 0;
}