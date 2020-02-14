#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string filename = "stats.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open()) {
        return 1;
    }

    while (input) {
        string line;

        // We use single quotes for char, double quotes for string
        getline(input, line, ':');

        int population;
        input >> population;

        cout << "'" << line << "'" << " -- " << population << endl;
    }

    input.close();

    return 0;
}