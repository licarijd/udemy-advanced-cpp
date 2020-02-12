#include <iostream>
using namespace std;

// Exceptions should generally be used for things that programs can't 
// recover from

void mightGoWrong() {
    bool error = true;

    if (error) {
        throw 8;
    }
}

int main() {
    mightGoWrong();

    return 0;
}