#include <iostream>
using namespace std;

// Functors are another way to pass blocks of code to functions.
// They're kind of like an alternative to function pointers, 
// with some advantages.

// There are things that can be done with functors which can't be done 
// with function pointers. But at other times, function pointers can be more 
// convenient.

// ** Note -n C++ 11, we have Lambda expressions which are really syntactic sugar 
// over functors.

struct Test {
    virtual bool operator()(string &text) = 0;
};

// We'll use a struct instead of a class, since by default class members and fuctions
// are private (they're public by default with structs).

// This struct is a functor.
// A functor is a class or a struct which, among other things, overloads the 
// brackets operator. Other than the brackets overload, there isn't much to 
// functors.

// This functor can be passed around to other functions.
// Then, we can have functions which can be passed types of tests (see check()).
struct MatchTest: public Test {

    // The bracket operator that surround function parameters are a special kind of 
    // operator since they can take a variable list of arguments, or no arguments.
    // Every other operator in C++ requires a non-variable list of arguments
    // (one, two, or three).
    // Like other operator, we can overload the bracket operators.

    // Now, we have the argument list (and that can be as many as we'd like).
    // The first set of brackets just indicates the operator we're dealing with
    // (paranthesis, in this case). It's just like overloading '+' and '=',
    // for example, with the difference being that the return type is bool
    // (we can choose the return type).
    bool operator()(string &text) {
        return text == "lion";
    }
};

// We'd like to be able to pass some sort of test/predicate
// to this function, that checks if the 'text' string passes the 
// test or not.

// We could do that with a function pointer parameter, and pass a 'test' function
// to do the testing. Another way is to use a functor.
// This is beneficial because we can pass different test functions using
// Polymorphism and subclass pointers.
void check(string text, Test &test) {

    // Remember, 'test' isn't a function! It's a functor, which is a class or
    // struct instance that overloads the '()' operator.
    if (test(text)) {
        cout << "Text matches!" << endl;
    } else {
        cout << "No match" << endl;
    }
}

int main() {
    
    // Usage:
    MatchTest predicate;

    string value =  "lion";

    // This looks like a function call but it's not.
    // It's really the brackets operator being applied using the 'predicate'
    // object to the 'value'.
    cout << predicate(value) << endl;

    MatchTest m;

    check("lion", m);

    return 0;
}

// Since functors are implemented using classes and structs, they have abilities 
// which function pointers don't. For example, they can have private variables,
// public variables, member functions, etc.

// In other cases, it would be less complicated to use function pointers.

// Lambda expressions in C++ 11 are syntactically simpler.