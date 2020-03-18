#include "Complex.h"

namespace justinlicari {

    ostream &operator<<(ostream &out, const Complex &c) {
        out << "(" << c.getReal() << "," << c.getImaginary() << ")";
        return out;
    }

    Complex::Complex(): real(0), imaginary(0) {

    }

    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {

    }

    // Copy constructor
    Complex::Complex(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
    }
    
    // We need :: because this is a member function of Complex.
    // The return type is const Complex reference (Complex &).
    const Complex & Complex::operator=(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }
}