#include <iostream>
#include <map>
using namespace std;

// Maps allow us to create collections of key-value pairs
// Maps store Pair types, which are another template class

int main() {

    map<string, int> ages;

    // Keys are unique
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    // We can also add pairs directly to maps
    pair<string, int> addToMap("Peter", 100);
    ages.insert(addToMap);
    // or
    ages.insert(pair<string, int>("Peter", 100));
    // or
    ages.insert(make_pair("Peter", 100));

    cout << ages["Raj"] << endl;

    // To test if a value is in the map
    if (ages.find("Vicky") != ages.end()) {
        cout << "Found Vicky" << endl;
    }

    // Iterating through maps
    for (map<string, int>::iterator it=ages.begin(); it != ages.end(); it++) {
        
        // -> points to a struct, which has fields first and second,
        // which are keys and values respectively
        cout << it -> first << ":" << it -> second << endl;
    }

    // Another way of iterating through maps using pairs
    for (map<string, int>::iterator it=ages.begin(); it != ages.end(); it++) {
        
        pair<string, int> age = *it;
        cout << age.first << ":" << age.second << endl;
    }

    return 0;
}