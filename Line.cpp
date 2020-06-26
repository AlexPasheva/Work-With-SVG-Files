#include "Line.h"
Line::Line(double startX, double startY, double endX, double endY, const char* color, unsigned int ID) : Shapes(startX, startY, color, ID)
{
	this->end.SetX(endX);
	this->end.SetY(endY);
}

Point Line::GetEnd()
{
	return end;
}

void Line::Print(ostream& strm)
{
	strm << "  <line ";
	start.Print(strm);
	end.Print(strm);
	strm << "fill=" << '"' << color << '"' << " " << "/>";
	strm << endl;
}
void Line::Print()
{
	cout << ID << ". line, ";
	start.Print();
	cout << ", ";
	end.Print();
	cout << ", ";
	cout << color;
	cout << endl;
}
void Line::Translate(double vertical, double horizontal)
{
	start.SetX(start.GetX() + horizontal);
	start.SetY(start.GetY() + horizontal);
	end.SetX(end.GetX() + horizontal);
	end.SetY(end.GetY() + horizontal);
}
bool Line::WithinRectangle(double startX, double startY, double width, double height)
{
	if (start.WithinRectangle(startX, startY, width, height) && end.WithinRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}
bool Line::WithinCircle(double startX, double startY, double radius)
{
	if (start.WithinCircle(startX, startY, radius) && end.WithinCircle(startX, startY, radius))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}

Shapes* Line::clone()
{
	return new Line(*this);
}
