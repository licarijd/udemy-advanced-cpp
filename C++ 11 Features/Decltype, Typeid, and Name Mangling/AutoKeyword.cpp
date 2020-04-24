#include <iostream>
using namespace std;

// What's really cool here is that we have a template function (recall templates
// simply take a parameter of type variable T, which allows it to work with various types)
// with a return type of whatever type 'T' is!
template<class T>
auto test2(T value) -> decltype(value) {
    return value;
}

// We can even use expressions with decltype!
template<class T, class S>
auto test3(T value, S value2) -> decltype(value + value2) {
    return value + value2;
}

// C++ 11 introduces training return types (a return type followong '->')
auto test() -> int {
    return 100;
}

int get() {
    return 999;
}

// With trailing return types, we can return a function call
auto test4() -> decltype(get()){
    return get();
}

int main() {

    // By default, in C++ 98 all variables are declared as 'auto'
    int value = 7;

    // This is the same as writing 
    // auto int c = 0;
    // in C++ 98
    int c = 8;

    // In C++ 11, the 'auto' keyword can be used to automatically determine the type
    // of a variable based on the value it's initialized with.
    auto value2 = 9;

    // Auto keywords are extremely convenient in cases where you have very long type declarations,
    // like when you're iterating through a vector.

    // It's also useful for the return types of functions (see test())
    cout << test() << endl;

    // 'auto' can be very useful for template functions (see template example)
    cout << test2("Hello world") << endl;
    cout << test3(5, 6);
    
    // We can also use 'auto' to allow for returning function calls
    cout << test4() << endl;

    // **Note that by default, 'auto' will declare character arrays (eg. "hello")
    // as strings. If we wanted something else, like a C-string for example, we'd
    // need to explicitly say so.

    return 0;
}