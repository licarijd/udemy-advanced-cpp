#include <iostream>
#include <vector>
using namespace std;

// Under the hood, the vector class will manage an array.
// When we resize a vector, it will copy the existing array
// to a new array

int main() {

    vector <double> numbers(20);

    // If we wanted to initialize every element to one, we'd do this:
    // vector <double> numbers(20, 1);

    cout << "Size: " << numbers.size() << endl;

    // capacity() gives the size of the internal array the vector is using
    int capacity = numbers.capacity();
    cout << "Capacity: " << numbers.capacity();

    for (int i = 0; i < 1000; i++) {

        // The capacity increases exponentially with the number of elements
        // This is because larger arrays than what we specify are used,
        // in case we resize the vector
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " << numbers.capacity();
        }
        numbers.push_back(i);
    }

    // Clears all elements from the vector.
    // This doesn't change the capacity of the internal array.
    numbers.clear();

    // Resizes the vector.
    // Existing elements at these indices will be kept.
    // This doesn't change the capacity of the internal array.
    numbers.resize(100);

    // Used to reserve more than what we're currently using.
    // This will increase the capacity, but the size remains the same.
    numbers.reserve(100);

    return 0;
}