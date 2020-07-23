#include <iostream>
using namespace std;

// Template classes allow you to design classes which work with types of variables that the
// user can specify. For example, vectors are a template class, and a member of
// The Standard Template Library. They involve combinations of variables
// which users (the programmer) defines.

// So, a template class is a template for a class - they define classes.

// T and K are type templates - we don't know what type they will be.
// The could be <string, int>, <double, int> etc. They're a type variable of sorts.

// It's common to use single letter variables since we don't know what type the user will make.
// T is traditional naming. Now, we can use T in our class as a type.
template<class T, class K>
class Test {

    // These are some examples of what we can do with T.
    // We can do operations and whatnot on it as if it were a an actual variable,
    // but we can't call methods on it obviously, since we don't know which methods it has.

    // Interrogating the object to see what type it is, and then conditionally calling
    // methods on it is bad practice - things should be encapsulated so we don't need to
    // know the type.
    private:
        T obj;

    // T and K are types. We don't know what they are, but we know we are expecting a variable of
    // type T, and a variable of type K.
    public:
        Test(T obj, K obj2) {
            this->obj = obj;
        }

        void print() {
            cout << obj << endl;
        }
};

int main() {

    cout << "Hello World" << endl;

    // This is useful if we're making a class that stores other objects of a specified type.
    Test<string, int> test1("Hello", 10);

    test1.print();

    return 0;
}