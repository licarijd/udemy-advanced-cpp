// Unique pointers are smart pointers which behave kind of like a 
// normal pointer, except they handle the deallocation of memory 
// for you.

// Memory leaks are generally a problem in C++ programs because 
// you don't get enough deletes bieng called, or the right delete 
// being called for the type of object you've allocated with new.

// Smart pointers help avoid those bugs by automatically deallocating memory.

#include <iostream>
#include <memory>

using namespace std;

class Test {

public:
    Test() {
        cout << "created" << endl;
    }

    void greet() {
        cout << "created" << endl;
    }

    ~Test() {
        cout << "destroyed" << endl;
    }
};

class Temp {

private:

// We can't just do this:

// unique_ptr<Test[]> pTest2(new Test [2]);

// because we're trying to call the constructor pTest2(...) directly here,
// which we're not allowed to do. We need to create a contructor for the 
// Temp class and use a constructor initialization list.
unique_ptr<Test[]> pTest2;

public:
    Temp(): pTest2(new Test[2]) {

    }
};

int main() {

    // Because we want this to manage the memory allocated, we can't just
    // do " = new int". We have to pass this information to the constructor
    // itself.
    unique_ptr<int> pTest(new int);

    // This gives us a basic pointer to an int, and we can use it just
    // like any pointer. We can dereference it and say

    *pTest = 7;

    // We can do a cout on it, and it'll behave just like a normal pointer.

    cout << pTest;

    // The difference is that it's going to deallocate the memory we've allocated
    // automatically!!

    unique_ptr<Test> pTest1(new Test);

    pTest1 -> greet();

    // After the variable hoes out of scope, the destructor is called! So in this case, 
    // once the end brace of main() is reached.

    // Before C++ 11, we had auto_ptr, which is now deprecated.

    // We can use unique pointers on arrays as well.

    unique_ptr<Test[]> pTest2(new Test [2]);

    pTest2[1].greet();

    // In this case, the entire array will be cleaned up when it goes out of
    // scope!!

    cout << "Finished" << endl;

    // See class Temp class for using unique pointers as private members of classes

    Temp temp;

    // If we create a Temp instance and run, we can see that 2 objects are being
    // created, and 2 objects are bieng destroyed. So, we no longer need to have a 
    // destructor that does deallocation. It happens automatically. So, even 
    // members that are unique_pointers get cleaned up!!

    return 0;
}
