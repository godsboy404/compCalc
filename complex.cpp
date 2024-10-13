// complex.cpp
#include "complex.h"

Complex::Complex(double real, double imag) : realPart(real), imagPart(imag) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(realPart + other.realPart, imagPart + other.imagPart);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(realPart - other.realPart, imagPart - other.imagPart);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(realPart * other.realPart - imagPart * other.imagPart,
                   realPart * other.imagPart + imagPart * other.realPart);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.realPart * other.realPart + other.imagPart * other.imagPart;
    return Complex((realPart * other.realPart + imagPart * other.imagPart) / denominator,
                   (imagPart * other.realPart - realPart * other.imagPart) / denominator);
}

double Complex::real() const {
    return realPart;
}

double Complex::imag() const {
    return imagPart;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.realPart;
    if (c.imagPart >= 0) {
        os << " + " << c.imagPart << "i";
    } else {
        os << " - " << -c.imagPart << "i";
    }
    return os;
}

std::string Complex::toString() const {
    std::string result = std::to_string(realPart);
    if (imagPart >= 0) {
        result += " + " + std::to_string(imagPart) + "i";
    } else {
        result += " - " + std::to_string(-imagPart) + "i";
    }
    return result;
}
