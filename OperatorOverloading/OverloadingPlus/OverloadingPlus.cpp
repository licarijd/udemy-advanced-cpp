#include <iostream>
#include "Complex.h"

using namespace std;
using namespace justinlicari;

int main() {
    
    Complex c1(3, 4);
    Complex c2(2, 3);

    cout << c1 + c2 << endl;

    Complex c4(4, 2);
    Complex c5 = c4 + 7;

    cout << c5 << endl;

    Complex c6(7, 7);

    // To do this, we'll have to overload the '+' operator in a new method
    // which accepts a double as the first parameter.
    Complex c7 = 7 + c6;

    cout << c7 << endl;

    return 0;
}