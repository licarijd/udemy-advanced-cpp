#include <iostream>
#include <vector>
using namespace std;

int main() {

    // A 2D vector is a vector of vectors.
    vector< vector<int> > grid(3, vector<int>(4, 0));

    // Since vectors can be resized, we can have a ragged array.
    grid[1].push_back(8);

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col<grid[row].size(); col++) {
            cout << grid[row][col] << flush;
        }

        cout << endl;
    }
}