#include <iostream>
#include "vector.h"

using namespace std;

Point addPoints(Point one, Point two){
  return Point( one.x + two.x, one.y + two.y);
}

// Subtracts point two from point one ( two - one )
Point subPoints(Point one, Point two)
{
  return Point( one.x - two.x, one.y - two.y);
}

// vector.cpp - method implementation
void Point::offset(double offsetX, double offsetY) {
    this->x += offsetX;
    y += offsetY;
}
void Point::print() {
    
    cout << "(" << x << "," << y << ")";
}
void Vector::offset(double offsetX, double offsetY) {
    start.offset(offsetX, offsetY);
    end.offset(offsetX, offsetY);
}

void Vector::print() {
    start.print();
    cout << " -> ";
    end.print();
    cout << endl;
}

Point::Point()
{
    x = 0.0;
    y = 0.0;
    std::cout << "Point constructor called" << std::endl;
}


Point::Point( double newx, double newy) {
    x = newx;
    y = newy;
}

// Point operator+(const Point &P) const;

Point Point::operator+(const Point& P) const
{
  return Point( this->x + P.x, this->y + P.y );      
}

Point Point::operator-(const Point& P) const
{
  return Point( this->x - P.x, this->y - P.y);
}
