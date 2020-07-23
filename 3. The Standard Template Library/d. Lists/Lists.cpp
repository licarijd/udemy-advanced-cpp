#include <iostream>
#include <list>
using namespace std;

// With lists, we can insert items into the start, middle, or end
// This is different from vectors, where we can only insert
// at the end.

// This is because for vectors, items are stored side by side
// in memory, which makes them easy to index.
// With a list, it contains a bunch of nodes, linked by pointers
// which points to the previous or next items.

int main() {

    list<int> numbers;

    // Works the same as with vectors
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    cout << "Element: " << *it << endl;

    list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;

    // erase() invalidates the iterator passed to it,
    // and returns a new iterator.
    eraseIt = numbers.erase(eraseIt);
    cout << "Element: " << *eraseIt << endl;

    // We also can also push to the front
    numbers.push_front(0);

    // We can erease and insert elements from a list as we iterate through it
    list <int>::iterator it2 = numbers.begin();
    while (it2 != numbers.end()) {
        if (*it2 == 2) {
            numbers.insert(it2, 1234);
        }

        // erase() effectively iterates the array
        if (*it2 == 1) {
            it2 = numbers.erase(it2);
        } else {
            it2++;
        }
    }

    // We can only increment the iterator with ++ or --
    // We can't do +=, eg. += 2
    for (list <int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}