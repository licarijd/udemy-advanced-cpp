#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public:

    // Constructors can take initializer lists as an argument.
    // The initializer list is a template, so we have to supply
    // a type.
    Test(initializer_list<string> texts) {

        // The initializer list is iterable, so we can use iterators with it
        // to access values.

        for(auto value: texts) {
            cout << value << endl;
        }
    }

    // We can even use initializer lists in functions!
    void print(initializer_list<string> texts) {
        for (auto value: texts) {
            cout << value << endl;
        }
    }
};

int main() {

    // An initializer list in usage can look kind of like this.
    vector<int> numbers { 1, 2, 3, 4 };
    cout << numbers[2] << endl;

    Test test{ "apple", "orange", "banana"};

    test.print({"one", "two", "three", "four"});

    return 0;
}