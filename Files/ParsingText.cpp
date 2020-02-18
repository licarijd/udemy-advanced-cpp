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

        // Gives us the last integer it's able to read, even if it's in error state
        input >> population;

        // Discards the return value of get(), which in this case is the newline character
        // input.get();

        // in C++ we can read whitespace like this
        // (does the same as input.get() in this case)
        input >> ws;

        // 'input' is overloaded for file streams to tell us if they're in error state or not
        if (!input) {

        }

        cout << "'" << line << "'" << " -- " << population << endl;
    }

    input.close();

    return 0;
}