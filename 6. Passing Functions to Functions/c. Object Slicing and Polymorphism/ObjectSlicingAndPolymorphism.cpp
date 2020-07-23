#include <iostream>
using namespace std;

class Parent {

public:

    // We need to define a regular constructor, or our copy contructor
    // will overwrite the implicit constructor (default implementation)
    // of our child class.
    Parent() {
        
    }
    
    // Since we're passing in an object of type Parent as a parameter,
    // child objects can be passed here as well (like in the example in main).
    Parent(const Parent &other) {
        cout << "Copy Parent";
    }

    /*virtual*/ void print() {
        cout << "parent" << endl;
    }
};

class Child: public Parent {
private:
    int two;
public:

    // We can't set private members of a parent class in a child class in C++.
    // The scope of private variables is limited to the class where it's defined.
    // That's why when we create a child class, we automatically get the constructors
    // of the parent class being run because the parent constructors can initialize
    // those private variables!

    // What we can initialize here is initialize the private variables of Child.
    Child(): /*one(0)*/ two(0) {

    }
    void print() {
        cout << "child" << endl;
    }
};

int main() {

    // Child and Parent both have print methods. The child prints "child" and
    // the parent prints "parent".
    // We would expect that this would call the child.
    Child c1;
    Parent &p1 = c1;
    p1.print();

    // In reality, this would call the parent's method.
    // Since we didn't make the function virtual, there's no 
    // lookup mechanism for C++ to find the right method to be called.

    // However, if we add the 'virtual' keyword in front of the Parent's print
    // method, it becomes a virtual method. C++ is going to create a table
    // of function pointers that point to the appropriate functions
    // for the right kinds of object.

    // The above is an example of Polymorphism - if you have a pointer to a 
    // parent class type (superclass), then we can point a pointer to any instance
    // of any subclass. This is because the subclass is a 'kind' of whatever the 
    // parent class is.

    // Then, as long as virtual methods are being used in the superclass,
    // we can call methods on the pointer and the right method will be invoked
    // for the particular kind of object.
    // This works for references as well, as we can see above.
    // We can take a reference to a parent class, refer to any object
    // of any subclass, and get the right method being called with the reference.

    Parent p2 = Child();
    p2.print();

    // This is copy initialization. If you declare a variable of a type and
    // set it equal to an object (Child() instantiates an object), even though 
    // we have an '=' operator, it invokes the copy constructor.
    // So in this case, it calls the parent class' copy constructor.

    // If no copy constructor is defined, then it will print the child instance's
    // print method (which may not be what you'd expect). To get things 
    // working, we need to define a copy constructor.

    // After we define both a constructor (so the child's implicit constructor
    // isn't overwritten) and a copy constructor, we can see that things work as
    // expected (the parent print method is called).

    // This gives rise to something called Object Slicing.

    // See the note regarding the Child constructor. Private variables can only be accessed
    // in the class that they are declared. Subclasses get superclass constructors,
    // and the constructors set superclass private variables. So, the private methods of
    // a parent are still useful. 
    // However, when we do
    // Parent p2 = Child();
    // we are essentially casting a child object to it's parent.
    // This is called up-casting (casting up the heirarchy of objects).
    // The private variables of the child are never set,
    // since the parent's copy constructor is unaware of the child's
    // private variables. So we can say we have
    // 'sliced' the child object (private variable 'two' is sliced off 
    // and thrown away, in this case).

    return 0;
}