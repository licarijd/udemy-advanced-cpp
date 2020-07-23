#include <iostream>

// In C++ 11 we can use Lambda expressions as an alternative to function pointers, 
// but it's still important to know function pointers.

// In the same way that we can declare a pointer to a variable in C++, we can declare a pointer
// to a function. Then, we can pass that function around. So in effect, we can pass a
// block of code to another function.

// Function pointers are actually used behind the scenes in C++.
// Virtual methods use function pointers implicitly, since the virtual keyword is an instruction
// call to C++ to create a virtual table.
// A virtual table is a table of function pointers; when you call a method in a child class
// via a pointer to the parent class, C++ will do a lookup on the table of function pointers
// to find the right function to call.

using namespace std;

void test(int value) {
    cout << value << endl;
}

int main() {
    test(5);

    // Brackets around the pointer means that we have a pointer to the function.
    // The second pair of brackets specify the parameter list (none, in this case).
    // void *pTest();
    // wouldn't work, since it's also a prototype for a function that 
    // takes the specified parameters, and has a return type of void pointer (we do have void
    // pointers in C++ that can point to any type).
    void (*pTest)(int);

    pTest = test;
    // pTest = &test;
    // works, but we actually don't need the '&' in this case.
    // This is because the name of a function is actually a pointer to the function in C++!

    // To call test, we'd use:
     pTest(5);

    // (*pTest)();
    // Works as well, but since pTest is a pointer, it's obvious that we want to call the 
    // call the function it points to.

    // We couldn't use:
    // *pTest();
    // since it could indicate a call to a function called pTest,
    // which returns a pointer to something (and then we're dereferencing the pointer).

    return 0;
}