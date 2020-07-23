#include <iostream>
#include <vector>
using namespace std;

class Test {

public:

    // Default constructor
    Test() {
        cout << "constructor" << endl;
    }

    // One parameter constructor
    Test(int i) {
        cout << "parameterized constructor" << endl;
    }

    // Copy constructor
    Test(const Test &other) {
        cout << "copy constructor" << endl;
    }

    // Assignment operator
    Test &operator=(const Test &other) {
        cout << "assignment" << endl;
        return *this;
    }

    // Destructor
    ~Test() {
        cout << "destructor" << endl;
    }

    // The "put to" operator, so we can use objects of this class
    // with cout.
    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
};

int main() {

    Test test1 = getTest();
    cout << test1 << endl;

    // A problem arises here. If we run this code with optimizations 
    // disabled in our compiler, then the result will be:
    // constructor
    // copy constructor
    // destructor
    // copy constructor
    // destructor
    // Hello from Test
    // destructor

    /*
    Explanation:

    First, the constructor runs when:
    return Test() is called.
    then, we have "copy constructor". The coy constructor is called when
    we have a function with a return type of a custom class, since a 
    copy of the object needs to be made for a temporary return value.

    Then we have have the destructor run for the unused temporary
    return value.

    Then, we have the copy constructor run again because we're copying
    the temporary return value to test 1 in:

    Test test1 = getTest();

    Remember that in cases like these where we declare and immediately 
    assign an object to another object, it runs the copy constructor,
    not the assignment operator (this is called copy initialization).

    Then, the destruct runs again because the temporary return value is 
    being destroyed.

    Then, we're seeing "hello from test", which is a result of using the
    overloaded "<<".

    And then the final "destructor" is because test1 goes out of scope at the 
    end of the program.
    */

   // Really, we just wanted to have a function "getTest" that initializes
   // objects. Despite our simple goal, we've ended up constructing 3 different
   // objects. It's clearly inefficient.

    // This example demonstrates copy ellision by disabling it with the 
    // flag "-fno-elide-constructors" for our compiler.

    // When we turn copy ellision back on, we can see the result is:

    /*
    constructor
    hello from test
    destructor
    */

    // The reason we got rid of all the temporary variables is that C++ can do
    // something called return value optimization. This involves elliding 
    // (getting rid of) extra copies of objects.

    // This happens in situations where we return local variables from functions
    // which are objects, and using it to initialize some other object outside
    // the function. In these situations, C++ can usually spot that we don't 
    // really want to temporary return value, and we don't really want to 
    // initialize another object.

    // So, unecessary copies are ellided away (this is copy ellision).

    // That being said, the "getTest" method of returning a constructor 
    // value is not best practice.

    // Another problem can be demonstrated with vectors.
    vector<Test> vec;
    vec.push_back(Test());

    /* The result from this would be:

    Hello from test
    constructor
    copy constructor
    destructor
    destructor
    destructor

    because once again, we'd need to construct the object, then copy it
    into the correct slot in the vector. Once again, very innefficient.

    C++ 11 solves this using something called R-Value references.
    Move constructors and move assignment operators. To be shown in later
    examples!
    */

    return 0;
}