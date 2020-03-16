#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Nested Standard Template Library types can be used to represent pretty much
// any data structure.

int main() {

    map<string, vector<int> > scores;

    scores["Mike"].push_back(10);
    scores["Bob"].push_back(50);
    scores["Bin"].push_back(70);

    for (map<string, vector<int> > :: iterator it = scores.begin(); it != scores.end(); it++) {

        string name = it -> first;
        vector<int> scoreList = it -> second;

        cout << name << ": " << flush;

        for (int i = 0; i < scoreList.size(); i++) {
            cout << scoreList[i] << " " << flush;
        }

        cout << endl;
    }

    return 0;
}