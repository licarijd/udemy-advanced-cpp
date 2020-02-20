#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Creates a vector which will contain 5 string type variables
    vector<string> strings(5);

    // The square bracket operaators have been overloaded for vectors,
    // so that vectors can work like arrays
    strings[3] = "dog";

    cout << strings[3] << endl;

    return 0;
}