#include <iostream>
using namespace std;

int main() {

    int cats = 5;

    // Here, we're calling the lambda expression directly.
    // Since "cats" is captured by value, the lambda expression doesn't
    // allow us to assign a value to it.
    // If we wanted to modify "cats", and have the variable behave as if it were
    // a paramter in a function, then we can do so using the "mutable" keyword.
    [cats]() mutable{
        // The local variable won't be changed.
        cats = 8;
        cout << cats << endl;
    }();

    cout << cats;

    return 0;
}