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
    double GetX();
    double GetY();

    // Distance to another point.  Pythagorean thm.
    double Dist(Point other);
    // Print the point on the stream.
    void Print(ostream& strm);
};
double Point::GetX() 
{ 
    return x;
}
double Point::GetY() 
{
    return y;
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
