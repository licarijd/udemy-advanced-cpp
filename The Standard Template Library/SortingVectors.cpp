#include <iostream>
#include <vector>
using namespace std;

// ** Note - sorts aren't efficient on vectors, so if sorts are frequently needed,
// it's better to use a set instead.

class Test {
    // By default, instance variables are private in C++ for classes.
    // In structs however, they're public by default.
    int id;
    // string name;

    public:

        string name;

        Test(int id, string name): id(id), name(name) {}

        void print() {
            cout << id << ": " << name << endl;
        }

        bool operator<(const Test& other) const {
            return name < other.name;
        }

        friend bool compFriend(const Test &a, const Test &b);
};

// Uses const since we don't intend to modify either object, just reference them.
// If we want this to work for private members, we can make it a friend function
// of the Test class.
bool comp(const Test &a, const Test &b) {
    return a.name < b.name;
}

bool compFriend(const Test &a, const Test &b) {
    return a.id < b.id;
}

int main() {
    vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(15, "Sue"));
    tests.push_back(Test(10, "Raj"));

    // Provide an iterator to the first element we want to sort,
    // and an iterator to the last element we want to sort.
    // For this to work, we'll have to implement the less than operator.
    // sort(tests.begin(), tests.end());

    // Sort also takes a third argument which is a function pointer, which we can use to
    // pass a compare function.
    // sort(tests.begin(), tests.end(), comp);
    sort(tests.begin(), tests.end(), compFriend);

    for (int i = 0; i < tests.size(); i++) {
        tests[i].print();
    }

    return 0;
}