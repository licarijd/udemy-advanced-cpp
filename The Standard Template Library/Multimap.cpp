#include <iostream>
#include <map>
using namespace std;

// Multimaps let you store values with duplicate keys.

int main() {

    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(50, "Vic"));
    lookup.insert(make_pair(30, "Bob"));
    lookup.insert(make_pair(10, "Rob"));

    // Prints out the map
    for (multimap<int, string>::iterator it=lookup.begin(); it != lookup.end(); it++) {
        cout << it -> first << ": " << it -> second << endl;
    }

    cout << endl;

    // Prints out the values in a map, after the object with the specified id is found
    for (multimap<int, string>::iterator it=lookup.find(10); it != lookup.end(); it++) {
        cout << it -> first << ": " << it -> second << endl;
    }

    cout << endl;

    // To get a range of elements in a map, we need to use a function called equal_range,
    // which returns a pair of iterators to the start and the end of the range.
    // The first and second iterators are stored in 'first' and 'second', respectively
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for (multimap<int, string>:: iterator it = its.first; it != its.second; it++) {
        cout << it -> first << ": " << it -> second << endl;
    }

    cout << endl;

    // In C++ 11, we can simplify the above code by using the keyword 'auto',
    // which automatically gets the type for you (instead of having to type out
    // a massive type string).

    auto its2 = lookup.equal_range(30);

    for (multimap<int, string>:: iterator it = its2.first; it != its2.second; it++) {
        cout << it -> first << ": " << it -> second << endl;
    }    

    return 0;
}