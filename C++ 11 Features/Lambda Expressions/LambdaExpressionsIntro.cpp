#include <iostream>
using namespace std;

// Earlier in the course we saw function pointers, which is a way of passing blocks of
// code to functions. We can essentially store a function in a variable. Functors, which
// we've seen as well, are basically another way of achieving the same thing.

// C++ has an ever nicer way of doing this with lambda expressions. There will still
// be cases where it'd be useful to use function pointers or functors, but
// lambda expressions are good if you have a simple function that you need to pass
// around.

// Since a lambda expression is essentially a lambda expression, the function 
// parameter is a void function pointer.
// The pair of brackets after the function pointer is where we define what 
// parameters the anonymous function will take.
void test(void (*pFunc)()) {
    pFunc();
};

int main() {

    // Square brackets are a distinguishing feature of lambda expressions.
    // This is similar to an anonymous function (in JavaScript for example).
    // The function doesn't have a name; parameters are in the brackets, and
    // code goes in the curly brackets.
    [](){
        cout << "Hello" << endl;
    };

    // We can assign anonymous functions to variables like this.
    // The type is complex to explain; it's a type of functor. But the 
    // easiest way to go is to just use "auto".
    auto func = [](){
        cout << "Hello 2" << endl;
    };

    // We can also call lambda expressions directly, although there isn't 
    // usually a reason to do this:
    [](){
        cout << "Hello" << endl;
    }();

    func();

    test(func);

    // It's not recommended, but we can also specify the lambda expression directly.
    // This works because the parameter of 'test' is a function pointer, so 
    // it's compatible with expressions.
    test([](){
        cout << "Hello" << endl;
    });    

    return 0;
}