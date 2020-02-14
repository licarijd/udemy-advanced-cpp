#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string inFileName = "test.txt";
    ifstream inFile;

    inFile.open(inFileName);

    if (inFile.is_open()) {
        
        string line;

        // The bool operator (including '!') has been overloaded for ifstream.
        // So, we don't have to check '!inFile.eof()'
        while(inFile) {
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();

    } else {
        cout << "Cannot open file" << inFileName << endl;
    }

    return 0;
}