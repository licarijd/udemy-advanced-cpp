// To use Typeid, we need to include the typeinfo header.

#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    int value;
    string value2;

    // We can use typeid to interrogate this type and figure out what it is.
    // The result is 'i', which means 'integer type'.
    cout << typeid(value).name() << endl;

    // String will output something more complex. When we compile C to a binary file
    // using a C compiler (not C++), we'd see the actual names of functions
    // in the binary code. But with C++ we can overload functions, and attach them to 
    // classes as methods, so there needs to be additional information about the context
    // of the function. 
    // So, C++ does something called "Name Mangling", where it takes the names of things like
    // variables and functions, and adds a bunch of characters to them to give more
    // information about them (eg. do they belong to a class).
    // In the case of getting the type of a string, we see Name Mangling occur because 
    // 'string' is a class.
    cout << typeid(value2).name() << endl;

    // 'decltype' allows us to declare variables of an existing type.
    // We can also use it to form the return type of a function.

    // decltype will get the type of the variable passed into it,
    // (string) in this case. We can then use the returned type to 
    // declare variables of type string! This is the exact same as:
    // string name = "Bob".
    decltype(value2) name = "Bob";

    cout << name << endl;

    return 0;
}