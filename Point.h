#pragma warning(disable : 4996)
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

    // Distance to another point.
    double Dist(Point other);
    // Print the point on the stream.
    bool WithinRectangle(double startX, double startY, double width, double height);
    bool WithinCircle(double startX, double startY, double radius);
    void PrintCirc(ostream& strm);
    void Print(ostream& strm);
    void Print();
};

