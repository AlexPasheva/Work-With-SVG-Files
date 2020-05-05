#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
class Point
{
private:
    double x;
    double y;
public:
    Point(double x = 0, double y = 0);

    double GetX();
    double GetY();
    void SetX(double x);
    void SetY(double y);

    // Distance to another point.  Pythagorean thm.
    double Dist(Point other);
    // Print the point on the stream.
    void Print(ostream& strm);
};
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Point::GetX()
{
    return x;
}
double Point::GetY()
{
    return y;
}
void Point::SetX(double x)
{
    this->x = x;
}
void Point::SetY(double y)
{
    this->y = y;
}
double Point::Dist(Point other)
{
    double xd = x - other.x;
    double yd = y - other.y;
    return sqrt(xd * xd + yd * yd);
}
void Point::Print(ostream& strm)
{
    strm << "(" << x << "," << y << ")";
}
