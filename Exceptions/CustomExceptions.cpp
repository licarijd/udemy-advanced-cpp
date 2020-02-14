#include <iostream>
#include <exception>
using namespace std;

// Inherits from the C++ Exception class
class MyException: public exception {

    // from the online c++ reference, we see there's a 'what' method we can override
    public:

        // 'const throw' means this method won't throw an exception
        // this can allow the compiler to optimize code
        // eg. if there are variables being instantiated when an exception is thrown,
        // but the compiler sees that an exception can't be thrown, it won't bother instantiating
        // those variables

        // Arguably, instantiating many variables which are only instantiated when an exception is thrown
        // is bad coding anyways.

        // 'const throw' will cause your program to halt at runtime

        // Overall, disadvantages could outweigh the advantages, so it might be better not to use it
        virtual const char* what() const throw() {
            return "Something bad happened";
        }
};

class Test {
    public:

        // If we had 'void goesWrong() throw()', it'd result in a runtime error
        // This is because we're throwing an exception inside of a function which
        // doesn't throw exceptions (because of 'throw()')

        // the parameter list of 'throw()' specifies the errors that can be thrown
        // so, 'void goesWrong() throw(bad_alloc)' would mean that goesWrong can only throw
        // bad_alloc exceptions
        void goesWrong() {
            throw MyException();
        }
};

int main() {

    Test test;

    try {
        test.goesWrong();
    }
    catch(MyException &e) {
        cout << e.what() << endl;
    }
    return 0;
}