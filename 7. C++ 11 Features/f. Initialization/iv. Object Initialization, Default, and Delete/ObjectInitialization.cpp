#include <iostream>
using namespace std;

class Test {

    // In C++ 11, we can initialize these members.
    // We can also use the usual syntax of 
    // int id = 3;
    // Both are new features to C++ 11; C++ 98 did not allow the initialization of
    // members in the declaration.
    int id{ 3 };
    string name{ "Mike" };

public:

    // When we provide our own constructor in C++, we lose the implicit constructor
    // that every function has.

    // However, we can keep the implicit constructor by using the 'default' keyword.
    Test() = default;

    // We can also use this for copy constructors and assignment operators.
    // This just provides an obvious way to know that we are using the default
    // copy constructor.

    // Note that this here doesn't add any new functionality (like in the above
    // example with the constructor). It just makes it explicit that we're using
    // the default copy constructor:
    // Test(const Test &other) = default;
    // Test &operator=(const Test &other) = default;

    // We can also delete implicit implementations. This could be used with 
    // copy constructors for example, to make objects non-copyable.
    Test(const Test &other) = delete;

    // Now with the member initialization, we could create constructors which override 
    // some of the member values. Only the members set in this constructor will be
    // modified ('id' in this case), while the other members maintain their values.
    Test(int id):
        id(id) {

    }

    void print() {
       cout << id << ": " << name << endl; 
    }
};

int main() {

    Test test;
    test.print();

    // Override the 'id' parameter
    Test test1(77);
    test1.print();

    // This invokes the copy constructor. It won't work in this case because we
    // deleted the implicit copy constructor in an example above.
    // Test test2 = test1;

    Test test2;

    // This invokes the assingnment operator.
    test2 = test;

    return 0;
}