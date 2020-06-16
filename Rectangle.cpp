#include "Rectangle.h"
Rectangle::Rectangle(double startX, double startY, double width, double height, const char* color, unsigned int ID) :Shapes(startX, startY, color, ID)
{
	this->width = width;
	this->height = height;
}


double Rectangle::GetWidth()
{
	return width;
}
double Rectangle::GetHeight()
{
	return height;
}
void Rectangle::SetWidth(double width)
{
	this->width = width;
}
void Rectangle::SetHeight(double height)
{
	this->height = height;
}

void Rectangle::Print(ostream& strm)
{
	strm << "  <rect ";
	start.Print(strm);
	strm << "width=" << '"' << width << '"' << " height=" << '"' << height << '"' << " ";
	strm << "fill=" << '"' << color << '"' << " " << "/>";
	strm << endl;
}
void Rectangle::Print()
{
	cout << ID << ". rectangle, ";
	start.Print();
	cout << ", " << width << ", " << height << ", ";
	cout << color;
	cout << endl;
}
bool Rectangle::WithinRectangle(double startX, double startY, double width, double height)
{
	Point LeftUpperCorner(start.GetX() + this->GetWidth(), start.GetY() + this->GetHeight());
	Point RightUpperCorner(start.GetX(), start.GetY() + this->GetHeight());
	Point LeftBottomCorner(start.GetX() + this->GetWidth(), start.GetY());
	if (start.WithinRectangle(startX, startY, width, height) && LeftUpperCorner.WithinRectangle(startX, startY, width, height) && RightUpperCorner.WithinRectangle(startX, startY, width, height) && LeftBottomCorner.WithinRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}
bool Rectangle::WithinCircle(double startX, double startY, double radius)
{
}
void Rectangle::Translate(double horizontal, double vertical)
{
	start.SetX(start.GetX() + horizontal);
	start.SetY(start.GetY() + horizontal);
}

Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}
