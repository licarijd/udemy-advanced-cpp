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

        // bool (not bool &) since we're creating a new boolean variable.
        // We refer to the address of other (it's of type Complex &).
        // We don't modify the object, we use 'const',
        // which is the same as const { <method-body> }
        bool operator==(const Complex &other) const;

        bool operator!=(const Complex &other) const;

        Complex operator*() const;
};

// Prototype of the stream insertion operator.
ostream &operator<<(ostream &out, const Complex &c);

// Return type is Complex, not Complex reference.
// This is because we dont't return a reference - we return a brand new number.
// Arguments are references for efficiency (no need to create a copy).
Complex operator+(const Complex &c1, const Complex &c2);

// To handle cases where we add a non-complex number to a complex number,
// eg. adding a double which will be added to the real part, not the imaginary part.
Complex operator+(const Complex &c1, double d);

Complex operator+(double d, const Complex &c1);

}

#endif /* COMPLEX_H_ */