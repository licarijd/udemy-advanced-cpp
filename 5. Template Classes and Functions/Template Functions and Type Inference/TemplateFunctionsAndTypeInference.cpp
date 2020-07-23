#include <iostream>
using namespace std;

template<class T>

// If we specify that we want to use the template version using <>, then C++ will use the template version,
// and use type inference to figure out the type.
// It uses type inference by looking at the argument list to figure out what type we mean
// (in this case, the argument list is 'T n', so 'T' is the only type in the list)
// Example:
// print<>(6);
void print(T n) {
    cout << "Non-template version: " << n << endl;
}

// Otherwise, if we just do
// print(6);
// C++ will use this function, since it's better suited for integers.
void print(int n) {
    cout << n << "Non-template version: " << endl;
}

// Here,
// show<>() won't work.
// In order for C++ to infer the type, the type needs to be present in the argument list.
// However, we can do this:
// show<double>();
// We'd get a default value of 0.
template<class T>
void show() {
    cout << T() << endl;
}

int main() {

    print<string>("hello");
    print<int>(5);
    print(6);
    print("Hi There");
    show<double>();
    return 0;
}