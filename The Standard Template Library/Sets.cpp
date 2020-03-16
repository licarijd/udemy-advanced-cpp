#include <iostream>
#include <set>
using namespace std;

// A set only stores unique elements.

int main() {

    set<int> numbers;

    numbers.insert(5);
    numbers.insert(4);
    numbers.insert(3);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    // To find an element of a set
    set<int>::iterator itFind = numbers.find(30);

    if(itFind != numbers.end()) {
        cout << "Found: " << *itFind << endl;
    }

    // We can also find if an element is in a set like this.
    // This works because 0 is equivalent to 'false' in C++, and
    // 1 is equivalent to 'true'
    if (numbers.count(30)) {
        cout << "Number found" << endl;
    }

    // Adding custom objects to maps works the same with sets (add const print() and '<' override methods
    // to have an example that works similarly to the maps example)

    return 0;
}