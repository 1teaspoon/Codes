#include <iostream>

class Point {
public:
    double x, y;
    void offset(double offsetX, double offsetY);
    void print();
    Point operator+(const Point &P) const;
    Point operator-(const Point &P) const;
    Point();
    Point(double newx, double newy);
};

Point addPoints(Point one, Point two);
Point subPoints(Point one, Point two);


class Vector {
public:
    Point start, end;
    void offset(double offsetX, double offsetY);
    void print();
};