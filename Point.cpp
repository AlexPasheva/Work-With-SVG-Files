#include "Point.h"

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
void Point::SetX(const double x)
{
    this->x = x;
}
void Point::SetY(const double y)
{
    this->y = y;
}
bool Point::WithinRectangle(double startX, double startY, double width, double height)
{
    if (this->GetX() < startX + width && this->GetX() > startX && this->GetY() > startY && this->GetY() < startY + height)
        return true;
    else
        return false;
}
bool Point::WithinCircle(double startX, double startY, double radius)
{
    if (((this->GetX() - startX) * (this->GetX() - startX) + (this->GetY() - startY) * (this->GetY() - startY)) < radius * radius)
        return true;
    else
        return false;
}
double Point::Dist(Point other)
{
    double xd = x - other.x;
    double yd = y - other.y;
    return sqrt(xd * xd + yd * yd);
}
void Point::PrintCirc(ostream& strm)
{
    strm << "cx=" << '"' << x << '"' << " " << "cy=" << '"' << y << '"' << " ";
}
void Point::Print(ostream& strm)
{
    strm << "x=" << '"' << x << '"' << " " << "y=" << '"' << y << '"' << " ";
}
void Point::Print()
{
    cout << x << "," << y;
}