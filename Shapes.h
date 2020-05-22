#pragma once
#pragma warning(disable : 4996)
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
	virtual void Print(ostream& strm)=0;
	virtual void Translate(double vertical, double horizontal)=0;
	virtual bool WithinRectangle(double startX, double startY, double width, double height)=0;
	virtual bool WithinCircle(double startX, double startY, double radius)=0;

	virtual Shapes* clone()=0;
};

Shapes::Shapes(double x, double y, const char* color, unsigned int ID)
{
	this->start.SetX(x);
	this->start.SetY(y);
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
//--------------------------------------------------------------- "Shapes" is a class that holds the shared characteristics of all the other classes in that header.
//--------------------------------------------------------------- 
//--------------------------------------------------------------- 
class Line: public Shapes
{
private:
	Point end;
public:
	Line(double startX = 0, double startY = 0, double endX = 0, double endY = 0, const char* color = "Unidentified", unsigned int ID = 0);

	Point GetEnd();


	//Some Methods
	void Translate(double vertical, double horizontal);
	void Print(ostream& strm);
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	Line* clone();
};

Line::Line(double startX, double startY, double endX, double endY, const char* color, unsigned int ID): Shapes(startX,startY,color,ID)
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
	strm << ID << ". line, ";
	start.Print(strm);
	strm << ", ";
	end.Print(strm);
	strm << ", ";
	strm << color;
	strm << endl;
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

Line* Line::clone()
{
	return new Line(*this);
}
//--------------------------------------------------------------- 
//--------------------------------------------------------------- 
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
	void Print(ostream& strm);
	void Translate(double horizontal, double vertical);
	bool IsWithinRectangle(double startX, double startY, double width, double height);
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	virtual Circle* clone();
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
	strm << ID << ". circle, ";
	start.Print(strm);
	strm << ", " << radius << ", ";
	strm << color;
	strm << endl;
}
void Circle::Translate(double horizontal, double vertical)
{
	start.SetX(start.GetX() + horizontal);
	start.SetY(start.GetY() + horizontal);
}
bool Circle::IsWithinRectangle(double startX, double startY, double width, double height)
{
	Point rectangleCenter = Point((startX + width / 2),(startY + height / 2));

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
	if (this->IsWithinRectangle(startX,startY,width,height))
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
	if (this->GetRadius()<radius)
	{
		if (dist + radius < this->GetRadius())
		{
			this->Print(cout);
			return true;
		}
	}
	else if(dist + this->GetRadius() < radius)
	{
		this->Print(cout);
		return true;
	}
	else
	{
		return false;
	}
	
}

Circle* Circle::clone()
{
	return new Circle(*this);
}
//--------------------------------------------------------------- 
//---------------------------------------------------------------
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
	void Translate(double horizontal, double vertical);
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	virtual Rectangle* clone();
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
	strm << ID << ". rectangle, ";
	start.Print(strm);
	strm << ", " << width << ", " << height << ", ";
	strm << color;
	strm << endl;
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
	Point LeftUpperCorner(start.GetX() + this->GetWidth(), start.GetY() + this->GetHeight());
	Point RightUpperCorner(start.GetX(), start.GetY() + this->GetHeight());
	Point LeftBottomCorner(start.GetX() + this->GetWidth(), start.GetY());
	if (start.WithinCircle(startX, startY, radius) && LeftUpperCorner.WithinCircle(startX, startY, radius) && RightUpperCorner.WithinCircle(startX, startY, radius) && LeftBottomCorner.WithinCircle(startX, startY, radius))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}
void Rectangle::Translate(double horizontal, double vertical)
{
	start.SetX(start.GetX() + horizontal);
	start.SetY(start.GetY() + horizontal);
}

Rectangle* Rectangle::clone()
{
	return new Rectangle(*this);
}
//---------------------------------------------------------------
