#include <iostream>
#include <vector>
using namespace std;

// An advantage of using Vectors over arrays is that they're resizable.
// Thus, they manage memory for you automatically.
int main() {

    // Creates a vector which will contain 5 string type variables
    vector<string> strings(5);

    // The square bracket operaators have been overloaded for vectors,
    // so that vectors can work like arrays
    strings[3] = "dog";

    // By adding these, we now have 8 elements total
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    // This gives us an iterator, which points to the
    // first element in the vector.
    vector<string>::iterator it = strings.begin();
    
    // This iterator object overloads the * operator,
    // so we can now access the iterator as though it was a pointer,
    // by dereferencing it.
    // This outputs the first element of the vector.
    cout << *it << endl;

    // There's also a vector.end(), which returns an iterator which
    // points just after the end of the vector.

    // ++ is overloaded for the iterator to point to the next item
    it++;

    // We can use start() and end() to loop through the vector
    for (vector<string>:: iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    cout << strings[3] << endl;
    cout << strings.size() << endl;

    return 0;
}