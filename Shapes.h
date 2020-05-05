#pragma once
#include "Point.h"

class Line
{
private:
	Point start;
	Point end;
	char color[25];
	unsigned int ID;
public:
	Line(double startX = 0, double startY = 0, double endX = 0, double endY = 0, const char* color = "Unidentified", unsigned int ID = 0);

	char* GetColor();
	unsigned int GetID();
	void SetColor(char* color);
	void SetID(unsigned int ID);

	void Print(ostream& strm);
};
Line::Line(double startX, double startY, double endX, double endY, const char* color, unsigned int ID)
{
	start.SetX = startX;
	start.SetY = startY;
	end.SetX = endX;
	end.SetY = endY;
	strcpy(this->color, color);
	this->ID = ID;
}
char* Line::GetColor()
{
	return color;
}
unsigned int Line::GetID()
{
	return ID;
}
void Line::SetColor(char* color)
{
	strcpy(this->color, color);
}
void Line::SetID(unsigned int ID)
{
	this->ID = ID;
}
void Line::Print(ostream& strm)
{
	strm << "line ";
	start.Print(strm);
	strm << " ";
	end.Print(strm);
	strm << " ";
	strm << color;
}
//---------------------------------------------------------------
class Circle
{
private:
	Point center;
	double radius;
	char color[25];
	unsigned int ID;
public:
	Circle(double centerX = 0, double centerY = 0, double radius=0, const char* color = "Unidentified", unsigned int ID = 0);

	double GetRadius();
	char* GetColor();
	unsigned int GetID();
	void SetRadius(double radius);
	void SetColor(char* color);
	void SetID(unsigned int ID);
	
	void Print(ostream& strm);
};
Circle::Circle(double centerX, double centerY, double radius, const char* color, unsigned int ID)
{
	center.SetX = centerX;
	center.SetY = centerY;
	if (radius<0)
	{
		radius = abs(radius);
	}
	this->radius = radius;
	strcpy(this->color, color);
	this->ID = ID;
}
double Circle::GetRadius()
{
	return radius;
}
char* Circle::GetColor()
{
	return color;
}
unsigned int Circle::GetID()
{
	return ID;
}
void Circle::SetRadius(double radius)
{
	this->radius = radius;
}
void Circle::SetColor(char* color)
{
	strcpy(this->color, color);
}
void Circle::SetID(unsigned int ID)
{
	this->ID = ID;
}
void Circle::Print(ostream& strm)
{
	strm << ID << "circle ";
	center.Print(strm);
	strm << " " << radius << " ";
	strm << color;
}
//----------------------------------------------------------------
class Rectangle
{
private:
	Point FirstPoint;
	Point SecondPoint; 
	double width;
	double height;
	char color[25];
	unsigned int ID;
public:
	Rectangle(double FirstPointX = 0, double FirstPointY = 0, double SecondPointX = 0, double SecondPointY = 0, double width = 0, double height = 0, const char* color = "Unidentified", unsigned int ID = 0);

	double GetWidth();
	double GetHeight();
	char* GetColor();
	unsigned int GetID();
	void SetWidth(double width);
	void SetHeight(double height);
	void SetColor(char* color);
	void SetID(unsigned int ID);

	void Print(ostream& strm);
};
Rectangle::Rectangle(double FirstPointX, double FirstPointY, double SecondPointX, double SecondPointY, double width, double height, const char* color, unsigned int ID)
{
	FirstPoint.SetX = FirstPointX;
	FirstPoint.SetY = FirstPointY;
	SecondPoint.SetX = SecondPointX;
	SecondPoint.SetY = SecondPointY;
	this->width = width;
	this->height = height;
	strcpy(this->color, color);
	this->ID = ID;
}
double Rectangle::GetWidth()
{
	return width;
}
double Rectangle::GetHeight()
{
	return height;
}
char* Rectangle::GetColor()
{
	return color;
}
unsigned int Rectangle::GetID()
{
	return ID;
}
void Rectangle::SetWidth(double width)
{
	this->width = width;
}
void Rectangle::SetHeight(double height)
{
	this->height = height;
}
void Rectangle::SetColor(char* color)
{
	strcpy(this->color, color);
}
void Rectangle::SetID(unsigned int ID)
{
	this->ID = ID;
}
void Rectangle::Print(ostream& strm)
{
	strm << "rectangle ";
	FirstPoint.Print(strm);
	strm << " ";
	SecondPoint.Print(strm);
	strm << " " << width << " " << height << " ";
	strm << color;
}
