#include <iostream>
using namespace std;

class Parent {

};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

    Parent parent;
    Brother brother;

    // Revisit casting in C:
    float value = 3.23;

    cout << (int)value << endl;

    // We can also do:
    cout << int(value) << endl;

    // C++ gives us some more precisely defined types of casting that can help
    // reduce errors in programs. The simplest is the Static Cast.

    cout << static_cast<int>(value) << endl;

    // Previously, we'd use a C-style cast

    
    // Suppose we have a Parent pointer. We can set that to a pointer to one
    // of the child classes (one of it's descedants).

    Parent *pp = &brother;

    // This makes sense because the concept of Polymorphism is that we can use
    // a pointer or reference to a subclass in any situation where we expect a 
    // pointer or reference to a superclass.

    // The other way around, it doesn't work:
    // Brother *pb = &parent;

    // It will work if we use a static cast:
    Brother *pb = static_cast<Brother *>(&parent);

    cout << pb << endl;

    // This works, but it's dangerous because things can go wrong with virtual 
    // functions. Or we could have methods in Brother that don't exist in Parent.

    return 0;
}