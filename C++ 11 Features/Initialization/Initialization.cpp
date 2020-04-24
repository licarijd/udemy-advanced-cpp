#include <iostream>
#include <vector>
using namespace std;

int main() {

    // C++ 11 allows for easy initialization using curly braces

    // This is the same as
    // int value = 5
    // in C++ 98;
    int value{5};
    cout << value << endl;

    // Same as
    // string text = "Hello"
    string text{"Hello"};
    cout << text << endl;

    // Same as 
    // int numbers = {1, 2, 3}
    int numbers[]{1, 2, 3};
    cout << numbers[1];

    // The same works for pointers as well
    int *pInts = new int[3]{1, 2, 3};
    cout << pInts[1] << endl;
    delete pInts;

    return 0;
}