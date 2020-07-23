#include <iostream>
using namespace std;

class Test {

private:

    // ** Aside - variables of a class' instance are called instance variables!
    int one{1};
    int two{2};

public:
    void run() {
        int three{3};
        int four{4};

        // We can access variables in the scope of run() as expected, but we can't 
        // access member variables 'one' and 'two' without a reference to "this".
        // When passing the "this" reference, all member variables are passed by 
        // reference, and can thus be modified.

        // We can't pass all variables by value ('=') and then pass "this".
        // But, we can pass all variables by reference ('&') and then pass 'this'.
        auto pLambda = [&, this](){
            one = 1111;
            cout << one << endl;
            cout << three << endl;
            cout << three << endl;
        };
        pLambda();
    }
};

int main() {
    Test test;
    test.run();

    return 0;
}