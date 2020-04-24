#include <iostream>
#include <vector>
using namespace std;

int main() {

    auto texts = {"one", "two", "three"};

    // Normally, we'd iterate through 'texts' with a for-loop, but C++ 11 
    // introduces Enhanced Loops.
    for(auto text: texts) {
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);

    for (auto number: numbers) {
        cout << number << endl;
    }

    // Enhanced loops work for anything that is iterable, eg. arrays, vectors, 
    // strings, etc. Previously, we had to use an index based for-loop or an
    // iterator. Often times when we use iterators, the type of the iterator 
    // ends up bieng very complex. In C++ 11, we can just use 'auto' for the 
    // iterator type!

    return 0;
}