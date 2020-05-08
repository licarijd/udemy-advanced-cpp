#include <iostream>
using namespace std;

int main() {

    int one = 1;
    int two = 2;
    int three = 3;

    // We'll just use the trailing brackets to call the function for now, but 
    // in practice, immediately invoking a lambda expression is pretty useless.

    // If we wanted to capture local variables by value in this lambda expression,
    // we can use the square brackets.
    [one, two](){
        cout << one << two << endl;
    }();

    // To capture all local variables by value, we can use the "=" sign
    [=](){
        cout << one << two << endl;
    }();

    // Capture all local variables by value, except for some,
    // which will be caught by reference ('three' in this case).
    [=, &three](){

        // Since we've captured 'two' by value, we can't do:
        // two = 7;
        // But since we've captured three by reference, we can do:
        three = 7;
        cout << one << two << endl;
    }();

    // The variable 'three' which was changed in the lambda expression, is still changed
    // since it was copied by reference.
    cout << three << endl;

    // Capture all local variables by reference.
    [&](){

        two = 8;
        cout << two << endl;
    }();

    // Capture all local variables by reference, excpet some which are captured by value:
    [&, two, three](){

        one = 8;

        // We can't assign to 'two', since it was captured by value
        // two = 8;
        cout << two << endl;
    }();

    // So basically, we use '&' or '=' to specify passing by reference or value by 
    // default, followed by variables which are exceptions. If the default is 
    // pass by value, then the other variables which are pass by reference
    // must be specified with '&'.

    return 0;
}