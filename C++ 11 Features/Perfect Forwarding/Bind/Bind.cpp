// Bind allows you to create aliases to functions, kind of like function 
// pointers.

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int main() {

    // Normal way of calling this function
    cout << add(1, 2, 3) << endl;

    // Calling the function using bind
    // First argument is a function pointer to 'add'
    auto calculator = bind(add, 3, 4, 5);

    // Since we've bound all the arguments to calcluator, it will always be
    // called with those arguments.
    cout << calculator();

    // You don't need to supply function arguments to 'bind' (although it's 
    // not too useful sometimes). We can use placeholders instead.
    // This can be used similary to curried functions in Haskell!!!

    auto calculator1 = bind(add, _1, _2, _3);

    cout << calculator1(1, 2, 3);

    // The underscore number represents the order of arguments we supply later.
    // This function always has 10 as the first argument; then, 2 additional
    // arguments can be passed in for a total of 3.

    auto calculator2 = bind(add, 10, _1, _2);

    cout << calculator2(1, 2);

    // Since the underscore represents order, we can change the order of arguments
    // by doing something like this:

    auto calculator2 = bind(add, _3, _1, _2);

    cout << calculator2(1, 2, 3);

    // The above will call add (2, 3, 1)


    // You can bind methods as well as functions:
    // Test test;
    // auto calculate = bind(&Test:add, test, 2, 100, 1)

    // The above example would work if 'add' were a method of a class "Test".

    // You can also bind to static methods.

    return 0;
}