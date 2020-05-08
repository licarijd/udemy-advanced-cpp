#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

// The standard function type is a very nice convenience in C++ 11 which lets us
// easily define a type used to reference any callable type in C++ 11 (anything
// you can call with round brackets).


bool check(string &test) {
    return test.size() == 3;
}

class Check {
public:

    // Functor
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

// run() accepts anything that's callable (type function, which is a template type),
// returns a bool, and accepts a string.
// 'check' is the name we give the function parameter.
void run(function<bool(string&)> check) {

    string test = "dog";
    cout << check(test) << endl;
}

int main() {

    int size = 5;

    vector<string> vec{ "one", "two", "three" };

    // count_if is from <algorithm> (see imports).
    // we will use it to count the number of strings that have 3 characters in them.
    // The last parameter is an expression (here we define an expression, but in the
    // next example we use a function pointer instead).
    int count = count_if(vec.begin(), vec.end(), [size](string test){ return test.size() == size; });

    cout << count << endl;

    // We can also pass a function pointer to count_if

    count = count_if(vec.begin(), vec.end(), check);

    cout << count << endl;

    // We can even pass a functor to count_if (see class Check)

    count = count_if(vec.begin(), vec.end(), check1);

    cout << count << endl;

    // Basically, we can pass anything into count_if that's callable (anything
    // with round brackets at the end of it).
    // It does this using Standard Function (see run()).

    // Here, we pass 'run' a lambda expression
    auto lambda = [size](string test){ return test.size() == size; };
    run(lambda);

    // We can also pass it a functor
    run(check1);

    // We can also pass it a function pointer
    run(check);

    // We can use this syntax to define local variables as well.
    // Here we define a function with an int return type.
    function<int(int, int)> add = [](int one, int two) { return one + two; };
    cout << add(7, 3) << endl;

    return 0;
}