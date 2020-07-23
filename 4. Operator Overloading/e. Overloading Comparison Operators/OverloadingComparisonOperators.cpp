#include <iostream>
#include "Complex.h"
using namespace std;
using namespace justinlicari;

int main() {

    Complex c1(3, 2);
    Complex c2(3, 2);
    Complex c3(5, 3);

    if(c1 == c2) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }

    cout << endl;

    if(c1 == c3) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }

    cout << endl;

    return 0;
}