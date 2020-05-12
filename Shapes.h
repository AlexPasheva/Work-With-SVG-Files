#pragma once
#include "Point.h"
class Shapes
{
protected:
	Point start;
	char color[25];
	unsigned int ID;
public:
	Shapes(double x = 0, double y = 0, const char* color = "Unidentified", unsigned int ID = 0);
	//Getters and setters
	char* GetColor();
	unsigned int GetID();
	Point GetStart();
	void SetColor(char* color);
	void SetID(unsigned int ID);
	//Some Methods that are overwritten for different objects
	virtual void Print(ostream& strm);
	virtual void Translate(double vertical, double horizontal);
	virtual Shapes* Create(Shapes* array, int ArraySize);
	virtual void WhitinRectangle(double startX, double startY, double width, double height);
	virtual void WithinCircle(double startX, double startY, double radius);
};
Shapes::Shapes(double x, double y, const char* color, unsigned int ID)
{
	this->start.SetX = x;
	this->start.SetY = y;
	strcpy(this->color, color);
	this->ID = ID;
}
char* Shapes::GetColor()
{
	return color;
}
unsigned int Shapes::GetID()
{
	return ID;
}
Point Shapes::GetStart()
{
	return start;
}
void Shapes::SetColor(char* color)
{
	strcpy(this->color, color);
}
void Shapes::SetID(unsigned int ID)
{
	this->ID = ID;
}
void Shapes::Translate(double vertical, double horizontal)
{
	this->GetStart.SetX = this->GetStart.GetX + horizontal;
	this->GetStart.SetY = this->GetStart.GetY + vertical;
}
Shapes* Shapes::Create(Shapes* array, int ArraySize)
{
	Shapes* NewArray = new Shapes[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++)
	{
		NewArray[i] = array[i];
	}
	NewArray[ArraySize + 1] = Shapes();
	return NewArray;
}
void Shapes::WhitinRectangle(double startX, double startY, double width, double height)
{
	if (start.WithinRectangle(startX,startY,width,height))
		this->Print(cout);
}
void Shapes::WithinCircle(double startX, double startY, double radius)
{
	if (start.WithinCircle(startX, startY, radius))
		this->Print(cout);
}
//--------------------------------------------------------------- "Shapes" is a class that holds the shared characteristics of all the other classes in that header.


class Line: public Shapes
{
private:
	Point end;
public:
	Line(double startX = 0, double startY = 0, double endX = 0, double endY = 0, const char* color = "Unidentified", unsigned int ID = 0);
	Point GetEnd();
	//Some Methods
	virtual void Translate(double vertical, double horizontal);
	virtual void Print(ostream& strm);
	virtual Shapes* Create(Shapes* array, int ArraySize, double startX, double startY, double endX, double endY, const char* color, unsigned int ID);
	virtual void WhitinRectangle(double startX, double startY, double width, double height);
	virtual void WithinCircle(double startX, double startY, double radius);
};
Line::Line(double startX, double startY, double endX, double endY, const char* color, unsigned int ID): Shapes(startX,startY,color,ID)
{
	this->end.SetX = endX;
	this->end.SetY = endY;
}
Point Line::GetEnd()
{
	return end;
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
void Line::Translate(double vertical, double horizontal)
{
	this->GetStart.SetX = this->GetStart.GetX + horizontal;
	this->GetStart.SetY = this->GetStart.GetY + vertical;
	this->GetEnd.SetX = this->GetEnd.GetX + horizontal;
	this->GetEnd.SetY = this->GetEnd.GetY + vertical;
}
Shapes* Line::Create(Shapes* array, int ArraySize, double startX, double startY, double endX, double endY, const char* color, unsigned int ID)
{
	Shapes* NewArray = new Shapes[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++)
	{
		NewArray[i] = array[i];
	}
	NewArray[ArraySize + 1] = Line(startX,startY,endX,endY,color,ID);
	return NewArray;
}
void Line::WhitinRectangle(double startX, double startY, double width, double height)
{
	if (start.WithinRectangle(startX, startY, width, height)&&end.WithinRectangle(startX, startY, width, height))
	{
		this->Print(cout);
	}
}
void Line::WithinCircle(double startX, double startY, double radius)
{
	if (start.WithinCircle(startX, startY, radius)&&end.WithinCircle(startX, startY, radius))
		this->Print(cout);
}
//--------------------------------------------------------------- 


class Circle: public Shapes
{
private:
	double radius;
public:
	Circle(double centerX = 0, double centerY = 0, double radius=0, const char* color = "Unidentified", unsigned int ID = 0);
	//Getters and setters
	double GetRadius();
	void SetRadius(double radius);
	//Some methods
	virtual void Print(ostream& strm);
	virtual Shapes* Create(Shapes* array, int ArraySize, double startX, double startY, double radius, const char* color, unsigned int ID);
	virtual void WhitinRectangle(double startX, double startY, double width, double height);
	virtual void WithinCircle(double startX, double startY, double radius);
};
Circle::Circle(double centerX, double centerY, double radius, const char* color, unsigned int ID):Shapes(centerX, centerY, color, ID)
{
	if (radius<0)
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
	strm << ID << "circle ";
	start.Print(strm);
	strm << " " << radius << " ";
	strm << color;
}
Shapes* Circle::Create(Shapes* array, int ArraySize, double startX, double startY, double radius , const char* color, unsigned int ID)
{
	Shapes* NewArray = new Shapes[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++)
	{
		NewArray[i] = array[i];
	}
	NewArray[ArraySize + 1] = Circle(startX, startY, radius, color, ID);
	return NewArray;
}
void Circle::WhitinRectangle(double startX, double startY, double width, double height)
{

}
void Circle::WithinCircle(double startX, double startY, double radius)
{
	Point point(startX, startY);
	int dist = start.Dist(point);
	if (dist + radius < this->GetRadius())
		this->Print(cout);
}
//---------------------------------------------------------------


class Rectangle: public Shapes
{
private:
	double width;
	double height;
public:
	Rectangle(double FirstPointX = 0, double FirstPointY = 0, double width = 0, double height = 0, const char* color = "Unidentified", unsigned int ID = 0);
	//Getters and Setters
	double GetWidth();
	double GetHeight();
	void SetWidth(double width);
	void SetHeight(double height);
	//Some methods
	void Print(ostream& strm);
	virtual Shapes* Create(Shapes* array, int ArraySize, double startX, double startY, double width, double height, const char* color, unsigned int ID);
	virtual void WhitinRectangle(double startX, double startY, double width, double height);
	virtual void WithinCircle(double startX, double startY, double radius);
};
Rectangle::Rectangle(double startX, double startY, double width, double height, const char* color, unsigned int ID):Shapes(startX, startY, color, ID)
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
	strm << "rectangle ";
	start.Print(strm);
	strm << " " << width << " " << height << " ";
	strm << color;
}
Shapes* Rectangle::Create(Shapes* array, int ArraySize, double startX, double startY, double width, double height, const char* color, unsigned int ID)
{
	Shapes* NewArray = new Shapes[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++)
	{
		NewArray[i] = array[i];
	}
	NewArray[ArraySize + 1] = Rectangle(startX, startY, height, width, color, ID);
	return NewArray;
}
void Rectangle::WhitinRectangle(double startX, double startY, double width, double height)
{
	Point LeftUpperCorner(start.GetX() + this->GetWidth(), start.GetY() + this->GetHeight());
	Point RightUpperCorner(start.GetX(), start.GetY() + this->GetHeight());
	Point LeftBottomCorner(start.GetX() + this->GetWidth(), start.GetY());
	if (start.WithinRectangle(startX, startY, width, height) && LeftUpperCorner.WithinRectangle(startX, startY, width, height)&& RightUpperCorner.WithinRectangle(startX, startY, width, height)&& LeftBottomCorner.WithinRectangle(startX, startY, width, height))
	{
		this->Print(cout);
	}
}
void Rectangle::WithinCircle(double startX, double startY, double radius)
{
	Point LeftUpperCorner(start.GetX() + this->GetWidth(), start.GetY() + this->GetHeight());
	Point RightUpperCorner(start.GetX(), start.GetY() + this->GetHeight());
	Point LeftBottomCorner(start.GetX() + this->GetWidth(), start.GetY());
	if (start.WithinCircle(startX, startY, radius) && LeftUpperCorner.WithinCircle(startX, startY, radius) && RightUpperCorner.WithinCircle(startX, startY, radius) && LeftBottomCorner.WithinCircle(startX, startY, radius))
	{
		this->Print(cout);
	}
}
//---------------------------------------------------------------

