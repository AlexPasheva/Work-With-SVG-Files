#include "Circle.h"
Circle::Circle(double centerX, double centerY, double radius, const char* color, unsigned int ID) :Shapes(centerX, centerY, color, ID)
{
	if (radius < 0)
	{
		radius = abs(radius);
	}
	this->radius = radius;
}


double Circle::GetRadius()
{
	return radius;
}
void Circle::SetRadius(double radius)
{
	this->radius = radius;
}

void Circle::Print(ostream& strm)
{
	strm << "  <circle ";
	start.PrintCirc(strm);
	strm << "r=" << '"' << radius << '"' << " ";
	strm << "fill=" << '"' << color << '"' << " " << "/>";
	strm << endl;
}
void Circle::Print()
{
	cout << ID << ". circle, ";
	start.Print();
	cout << ", " << radius << ", ";
	cout << color;
	cout << endl;
}
void Circle::Translate(double horizontal, double vertical)
{
	start.SetX(start.GetX() + horizontal);
	start.SetY(start.GetY() + horizontal);
}
bool Circle::IsWithinRectangle(double startX, double startY, double width, double height)
{
	Point rectangleCenter = Point((startX + width / 2), (startY + height / 2));

	double w = width / 2;
	double h = height / 2;

	double dx = abs(start.GetX() - rectangleCenter.GetX());
	double dy = abs(start.GetY() - rectangleCenter.GetY());

	if (dx > (radius + w) || dy > (radius + h)) return false;

	Point circleDistance = Point((abs(start.GetX() - startX - w)), (abs(start.GetY() - startY - h)));

	if (circleDistance.GetX() <= (w))
	{
		return true;
	}
	if (circleDistance.GetY() <= (h))
	{
		return true;
	}
	double cornerDistanceSq = pow(circleDistance.GetX() - w, 2) + pow(circleDistance.GetY() - h, 2);

	return (cornerDistanceSq <= (pow(radius, 2)));
}
bool Circle::WithinRectangle(double startX, double startY, double width, double height)
{
	if (this->IsWithinRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	return false;
}
bool Circle::WithinCircle(double startX, double startY, double radius)
{
	Point point(startX, startY);
	double dist = start.Dist(point);
	if (this->GetRadius() < radius)
	{
		if (dist + radius < this->GetRadius())
		{
			this->Print(cout);
			return true;
		}
	}
	else if (dist + this->GetRadius() < radius)
	{
		this->Print(cout);
		return true;
	}
	else
	{
		return false;
	}

}

Shapes* Circle::clone()
{
	return new Circle(*this);
}
