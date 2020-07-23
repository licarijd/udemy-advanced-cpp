#include <iostream>
using namespace std;

class Parent {

    int dogs;
    string text;

public:

    // What we can't do in C++ 98 is call one constructor from
    // another within a class. But in C++ 11, we can do this.
    // This is called a delegating constructor.
    // In C++ 98, a common solution would be to use an "init" method, which
    // various constructors would call.
    Parent():Parent("hello") {
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
    Child(): Parent("hello") {

    }

    // We use:
    // Child() = default;
    // to use the default constructor.
};

int main() {
    Parent parent;
    Child child;
    return 0;
}