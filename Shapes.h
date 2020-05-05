#pragma once
#include "Point.h"
class Shapes
{
protected:
	Point start;
	char color[25];
	unsigned int ID;
public:
	//Getters and setters
	char* GetColor();
	unsigned int GetID();
	Point GetStart();
	void SetColor(char* color);
	void SetID(unsigned int ID);
	//Some Methods that are overwritten for different objects
	virtual void Print(ostream& strm) = 0;
	virtual void Translate(double vertical, double horizontal);
};
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
//--------------------------------------------------------------- The translation in class Line behaves diferently and because of that it is overwritten.
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
};
Circle::Circle(double centerX, double centerY, double radius, const char* color, unsigned int ID)
{
	start.SetX = centerX;
	start.SetY = centerY;
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
};
Rectangle::Rectangle(double startX, double startY, double width, double height, const char* color, unsigned int ID)
{
	start.SetX = startX;
	start.SetY = startY;
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
//---------------------------------------------------------------
//Shapes* shapeCollection[10] ;
//shapeCollection[0] = new Circle(parameters);
void TranslateShape(Shapes* array, int ArraySize, double vertical, double horizontal, int n = -1)//this function works with array like the one above
{                                                                                                // it may work better with std container tho
	if (n==-1)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			array[i].Translate(vertical, horizontal);
		}
	}
	else
	{
		array[n].Translate(vertical, horizontal);
	}
}
