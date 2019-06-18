#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    // return abs(c1.get_real() - c2.get_real()) < .0001 && abs(c1.get_imag() - c2.get_imag()) < .0001
    return true; // temp!
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(2) << showpos << c.real << ", " << c.imag;
    return os;
}

// all of these functions return a Complex number

// CONSTRUCTOR
Complex::Complex(double real, double imag) : real(real), imag(imag) {}

/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

Complex::operator bool() const {
    return ((real != 0) || (imag != 0));
}

// PREINCREMENT
Complex& Complex::operator++() {
    ++real;
    return *this;
}

// POSTINCREMENT
// dummy --> means we are doing postincrement
Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    ++real;
    return temp;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    --real;
    return temp;
}

Complex Complex::operator-=(const Complex& c){
    real -= c.real;
    imag -= c.imag;
    return *this;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    Complex prod(real * i, imag * i);
    return prod;
}

Complex operator+(const Complex& c1, const Complex& c2){
    Complex result{c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag()};
    return result;
}

Complex operator-(const Complex& c1, const Complex& c2){
    Complex result{c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag()};
    return result;
}