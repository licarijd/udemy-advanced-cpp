#include <iostream>
#include "Complex.h"

using namespace std;
using namespace justinlicari;

int main() {

    Complex c1(2, 3);

    // Uses the copy constructor.
    Complex c2 = c1;

    // Uses the copy constructor.
    Complex c3 = c2;

    cout << c2 << ": " << c3 << endl;

    return 0;
}