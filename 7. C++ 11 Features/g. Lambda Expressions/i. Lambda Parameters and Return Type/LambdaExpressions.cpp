#include <iostream>
using namespace std;

// We don't have to give the anonymous function parameter a name.
void testGreet(void (*greet)(string/* name*/)) {
    greet("bob");
}

void runDivide(double (*divide)(double a, double b)) {

    auto rval = divide(9, 3);
    cout << rval << endl;
}

int main() {

    auto pGreet = [](string name){
        cout << "Hello" << name << endl;
    };

    pGreet("Mike");

    testGreet(pGreet);

    // Lambda expressions and return types.

    // There's no need to specify a return type here; C++ infers it.
    auto pDivide0 = [](double a, double b){

        return a / b;
    };

    cout << pDivide0(10.0, 5.0);

    // The above is fine if there's only one return statement; if there's multiple
    // return statements which return different types, then C++ can't infer.

    // Here, we have 2 possible return types: int and double.
    // So, C++ can't infer the return type as if there were a single return type.
    // So, we have to explicitly specify the return type with the trailing return
    // type syntax.

    auto pDivide = [](double a, double b) -> double {

        if (b == 0.0) {
            return 0;
        } 
        return a / b;
    };

    runDivide(pDivide);

    return 0;
}