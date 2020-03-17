#include <iostream>
using namespace std;

class Test {

    private:
        int id;
        string name;

    public:
        Test(): id(0), name("") {

        }

        Test(int id, string name): id(id), name(name) {

        }

        void print() {
            cout << id << ": " << name << endl;
        }

        const Test &operator=(const Test &other) {

            cout << "Assignment operator running..." << endl;
            id = other.id;
            name = other.name;

            // Return a reference to the object we're in.
            return *this;
        }

        // Copy Constructor.
        // C++ has a general rule called the rule of 3.
        // It means that if you implement one of:
        // - copy constructor
        // - asignment operator
        // - destructor
        // then you should implement all 3.
        Test(const Test &other) {
            cout << "Copy constructor running..." << endl;
            id = other.id;
            name = other.name;

            // The above assignments are equivalent to:
            // *this = other
        }
};

int main() {

    Test test1(10, "Mike");

    cout << "Print test 1" << flush;

    test1.print();

    Test test2(20, "Bob");

    cout << "Print test 2" << flush;

    // This will work as expected - C++ provides a default implementation of '=',
    // which does a shallow copy.
    // Other times, we may need a deep copy. An example would be if we want to copy
    // everything from test1, except for an id, and use a different id.
    // Or, we may have pointers in test1. If we try copoying those, then we're stealing
    // the memory allocated by test1, rather than allocating our own memory.
    test2 = test1;
    test2.print();

    // The '=' operator implicitly takes the object calling it as the first parameter
    // (which we can reference with 'this'), can takes one more object as a paramter.
    // So, '=' is basically a method. If we overload it and provide a reference to the resulting
    // copy as a return value, then we can chain together method calls like this:
    Test test3;
    test3 = test2 = test1;

    // We can also do this (this is the default C++ implementation of '=', regardless of whether
    // we overload it or not):
    test3.operator=(test2);

    cout << "Print test 3" << flush;

    test3.print();

    cout << endl;

    // Copy constructor invoked here instead of overloading assignment operator.
    // This is because we didn't provide test4 with initial values; we initialized it to
    // test1, essentially copying it in declaration.
    // By the Rule of 3, it also makes sense that we'd define a copy constructor as
    // well as an assignment operator.

    // It makes sense that we'd want to implement a copy constructor and assignment operator
    // when we implement a destructor, because if we need a destructor, we're cleaning up memory.
    // And if pointers are being used, then we need to make sure the data they point to
    // is being copied / assigned properly (not with a shallow copy).
    Test test4 = test1;

    test4.print();

    return 0;
}