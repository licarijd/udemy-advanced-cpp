// Shared pointers are very similar to unique pointers, except they don't
// delete the memory associated with your objects until all the pointers
// that point to that object have gone out of scope.

// In C++ 11, you can't use shared pointers to point to arrays, but
// that may have changed in C++ 2017.

#include <iostream>
using namespace std;

class Test {

public:
    Test() {
        cout << "created" << endl;
    }

    void greet() {
        cout << "Hello" << endl;
    }

    ~Test() {
        cout << "destroyed" << endl;
    }
};

int main() {

    // One way to create a shared pointer is the same way we created a unique
    // pointer.

    // shared_ptr<Test> pTest1(new Test);

    // The best way to create a shared pointer is to use the make_shared macro.

    shared_ptr<Test> pTest1 = make_shared<Test>();

    // We don't have to use "new" ourselves, it's just like a template function.
    // According to the documentation, using the <> to define type is more efficient 
    // than using "new" yourself.

    // Now, we'll make another pointer that points to pTest1

    shared_ptr<Test> pTest2 = pTest1;

    // We won't have the memory for pTest1 deallocated until all pointers (ie pTest2)
    // referencing it have also been deleted.

    // In this case, the result will be the same because ptest1 and pTest2 are in the same scope.

    cout << "Finished" << endl;

    // ** In general, since they work the exact same way as regular pointers, you
    // can replace all your pointers with unique pointers most of the time.
    // And, if you have a situation where you want all that memory to hang around until 
    // all the pointers have gone out of scope, you can use shared pointers.

    return 0;
}