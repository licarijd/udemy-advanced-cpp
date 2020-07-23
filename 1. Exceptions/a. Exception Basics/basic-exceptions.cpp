#include <iostream>
using namespace std;

// Exceptions should generally be used for things that programs can't 
// recover from

void mightGoWrong() {
    bool error1 = false;
    bool error2 = true;

    if (error1) {

        // We can throw an error of any type (string, int, even objects)
        throw 8;
    }
    if (error2) {

        // If we use an object, we initialize it
        // we don't need to use 'new' because the compiler will take care
        // of creating and destroying this object
        throw string("Something else went wrong");
    }
}

int main() {
    try {
        mightGoWrong();
    }

    // In this case, the error is of type int because that's we threw
    // if we threw a string, eg "error", then 'e' would be of type string
    catch(int e) {
        cout << "error code: " << e << endl;
    }
    catch(char const * e) {
        cout << "error message: " << e << endl;
    }
    catch(string e) {
        cout << "String error message";
    }

    cout << "   ...still running";

    return 0;
}