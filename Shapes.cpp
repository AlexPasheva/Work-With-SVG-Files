#include "Shapes.h"
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