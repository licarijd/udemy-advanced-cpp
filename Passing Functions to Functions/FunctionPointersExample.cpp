#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test) {
    return test.size() == 3;
}

// Our own implementation of 'count_if', just to demonstrate a use for function 
// pointers.
int countStrings(vector<string> &texts, bool (*match)(string test)) {

    int tally = 0;
    for(int i = 0; i < texts.size(); i++) {
        if (match(texts[i])) {
            tally++;
        }
    }

    return tally;
}

int main() {
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("six");
    texts.push_back("seven");
    texts.push_back("eight");

    // If we include 'algorithm', we can use the 'count_if' function to apply a function
    // to each element in a vector. It takes an iterator to start at, an iterator to end at, 
    // and a pointer to a function that returns a condition.
    // count_if will return the number of vector elements that meet the condition.
    count_if(texts.begin(), texts.end(), match);

    cout << countStrings(texts, match) << endl;

    return 0;
}