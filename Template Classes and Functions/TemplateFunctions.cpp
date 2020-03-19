#include <iostream>
using namespace std;

// Template functions can be part of classes, and template classes.
// Similarly to template classes, we generally want to use template functions when we're
// making something should work on various types, depending on the type the user implements.
// For example, stream insertion operators '<<' can be used on strings, integers, double, etc.

// Using 'typename T' works the same as 'class T', for both classes and functions.
// This makes sense, since T might be a primitive type instead of a class.
template<class T>
void print(T n) {
    cout << n << endl;
}

int main() {

    print<string>("hello");
    print<int>(5);

    cout << endl;

    // This works as well because of type inference - C++ looks at the type and infers
    // what type we want. It's the same as
    // print<string>("Hi There");
    print("Hi There");
    return 0;
}