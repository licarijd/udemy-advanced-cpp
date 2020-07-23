#include <iostream>
#include <vector>
using namespace std;

int main() {

    // C++ 11 allows for easy initialization using curly braces

    // This is the same as
    // int value = 5
    // in C++ 98;
    int value{5};
    cout << value << endl;

    // Same as
    // string text = "Hello"
    string text{"Hello"};
    cout << text << endl;

    // Same as 
    // int numbers[] = {1, 2, 3}
    int numbers[]{1, 2, 3};
    cout << numbers[1] << endl;

    // The same works for pointers as well
    int *pInts = new int[3]{1, 2, 3};
    cout << pInts[1] << endl;
    delete pInts;

    // Empty braces can be used to initialize things to zero.
    int value1 = {};
    cout << value1 << endl;

    // We can also use braces to initialize pointers.
    int *pSomething{&value};

    // And we can use this to create null pointers.
    // This is equivalent to:
    // int *pSomething = nullptr;
    int *pSomething2{};

    cout << pSomething2 << endl;

    // Empty braces to initialize things to zero (or the zero equivalent for the given type)
    // also works for arrays. Here, numbers[1] will be zero (all indexes will be zero)
    int numbers1[5]{};
    cout << numbers[1] << endl;

    // We can also do this for classes (see s1 declaration).
    struct {
        
        int value;
        string text;
    } s1 { 5, "Hi" };

    cout << s1.text << endl;

    // Lastly, curly brackets can be used to vastly simplify initializing vectors
    // in C++ 11! This works by using initialization lists (next tutorial).
    vector<string> strings{
        "one",
        "two",
        "three"
    };

    return 0;
}