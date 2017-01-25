//  complex.cpp
//  Homework 02
//  Author: 

#include "complex.h"
#include <math.h>

// Constructors
Complex::Complex() : m_Real(0), m_Imaginary(0) {}

Complex::Complex (double a, double b) : m_Real(a), m_Imaginary(b) {}

// Destructor
Complex::~Complex() {}

// Magnitude of this Complex number
double Complex::magnitude() const {
    // TODO: Calculate the magnitude
    double magnitude;
    magnitude = sqrt(m_Real*m_Real+m_Imaginary*m_Imaginary);
    return magnitude;
}

// Addition of complex numbers is defined as:
// (a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::operator+(const Complex & c) const {
    //TODO: Addition of complex numbers
    Complex addition;
    addition.m_Real = m_Real+c.m_Real;
    addition.m_Imaginary = m_Imaginary+c.m_Imaginary;
    return addition;
}

// Subtraction of complex numbers is defined as:
// (a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(const Complex & c) const {
    //TODO: Subtraction of complex Numbers
    Complex subtraction;
    subtraction.m_Real = m_Real-c.m_Real;
    subtraction.m_Imaginary = m_Imaginary-c.m_Imaginary;
    return subtraction;
}

// Multiplication of complex numbers is defined as:
// (a + bi)(c + di) = (ac - bd) + (bc + ad)i
Complex Complex::operator*(const Complex & c) const {
    //TODO: Multiplication of Complex numbers
    Complex multiplication;
    multiplication.m_Real = m_Real*c.m_Real - m_Imaginary*c.m_Imaginary;
    multiplication.m_Imaginary = m_Imaginary*c.m_Real+ m_Real*c.m_Imaginary;
    return multiplication;
}

// Division
Complex Complex::operator/(const Complex & c) const {
    //TODO: Division of Complex numbers
    Complex division;
    division.m_Real = (m_Real*c.m_Real + m_Imaginary*c.m_Imaginary)/(c.m_Real*c.m_Real+c.m_Imaginary*c.m_Imaginary);
    division.m_Imaginary = (m_Imaginary*c.m_Real- m_Real*c.m_Imaginary)/(c.m_Real*c.m_Real+c.m_Imaginary*c.m_Imaginary);
    return division;
}

// friend function. Notice the lack of complex scope. Why?
std::ostream & operator << (std::ostream & out, const Complex & c)
{
    std::cout << "(" << c.m_Real << " + " << c.m_Imaginary << "i)";
    return out;
}
