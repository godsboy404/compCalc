// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0);

    // 复数加法
    Complex operator+(const Complex& other) const;

    // 复数减法
    Complex operator-(const Complex& other) const;

    // 复数乘法
    Complex operator*(const Complex& other) const;

    // 复数除法
    Complex operator/(const Complex& other) const;

    // 获取实部
    double real() const;

    // 获取虚部
    double imag() const;

    // 输出复数
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

    // 转换为字符串
    std::string toString() const;

private:
    double realPart;
    double imagPart;
};

#endif // COMPLEX_H
