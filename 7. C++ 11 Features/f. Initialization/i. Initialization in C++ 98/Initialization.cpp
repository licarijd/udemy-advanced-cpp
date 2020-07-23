#include <iostream>
#include <vector>
using namespace std;

int main() {

    // We can use curly brackets to initialize values
    int values[] = {1, 2, 3};

    cout << values[0] << values[1] << values[2];


    // We can also use curly brackets initialize public members of a class / struct.
    // This style of initialization is more commonly used with structs, since
    // struct members are public by default.

    class C {
    public:
        string text;
        int id;
    };

    C c1 = {"Hello", 7};

    cout << c1.text << endl;

    // With structs, we can also initilalize member variables right after
    // declaring the struct Here, we declare r1 right after the closing bracket of the struct.

    struct R {
        string text;
        int id;
    } r1 = { "Hello", 7};

    cout << r1.text << endl;

    // We don't even have to name the struct if we don't plan on using it later

    struct {
        string text;
        int id;
    } r2 = { "Hello", 7}, r3 = {"Hi", 0};

    cout << r2.text << r3.text << endl;

    // Curly brackets are pretty limited in C++ 98. There's a particular deficiency with
    // vectors. To initialize all the values in a vector, we have to go through this tedious
    // process of pushing back items.

    // What we'll see is that in C++ 11, we can use curly brackets everywhere to 
    // initialize things.

    vector<string> strings;

    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");

    return 0;
}