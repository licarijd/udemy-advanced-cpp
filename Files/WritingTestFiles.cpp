#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outFile;

    string outputFileName = "text.txt"

    outFile.open(outputFileName);

    if (outfile.is.open()) {

    } else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    return 0;
}