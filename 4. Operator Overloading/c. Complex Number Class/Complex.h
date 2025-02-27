#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace justinlicari {

class Complex {

    private:
        double real;
        double imaginary;

    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex &other);
        const Complex &operator=(const Complex &other);

        // We need to declare these as const so C++ knows we won't change the method
        // (and so we can use 'const Complex &c' in the stream operator overload
        // in Complex.cpp).
        double getReal() const { return real; }

        double getImaginary() const { return imaginary; }
};

// Prototype of the stream insertion operator.
ostream &operator<<(ostream &out, const Complex &c);

}

#endif /* COMPLEX_H_ */