#include <iostream>
using namespace std;

// This demonstrates a related concept in C++ 98.

// In C++ 98, when we have a subclass and a superclass:
// When the child object is constructed, it must run the parent in the 
// superclass. This is because the child will inherit from the parent.
// So, parent constructors will be called from the child class.

class Parent {

    int dogs;
    string text;

public:

    // We need to define this no parameter constructor because we lose the 
    // default no parameter constructor when we define the constructor that
    // takes one argument.
    // Otherwise, when "Child child" runs, there's an error.
    Parent() {
        dogs = 5;
        cout << "No parameter parent constructor" << endl;
    }
    Parent(string text) {

        dogs = 5;
        this->text = text;

        cout << "string parent constructor" << endl;
    }
};

class Child: public Parent {
public:
    // We can specify which constructor of "Parent" to run.
    // By default this would run the Parent constructor which takes no 
    // arguments, but we specify that the one which takes one argument 
    // should be used.
    Child(): Parent("hello") {

    }
};

// What we can't do in C++ 98 is call one constructor from another within a class.
// See DelegatingConstructors.cpp.

int main() {
    Parent parent;
    Child child;
    return 0;
}