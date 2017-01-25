//  complex.h
//  Homework 02
//  Author: Jiahui Wang

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    double      m_Real;
    double      m_Imaginary;

    Complex();
    Complex (double a, double b);
    ~Complex();

    double magnitude() const;

    Complex operator*(const Complex & c) const;
    Complex operator+(const Complex & c) const;
    Complex operator-(const Complex & c) const;
    Complex operator/(const Complex & c) const;

    friend std::ostream & operator << (std::ostream & out, const Complex & c);
};

#endif
