#pragma once
#include "Commands.h"
class ShapesContainer
{
private:
	Shapes** shapes;

	int capacity;
	int count;

	void CopyFrom(const ShapesContainer& other);
	void Free();
	void Resize(int NewCappacity);

public:
	ShapesContainer();
	ShapesContainer(const ShapesContainer& other);
	ShapesContainer& operator=(const ShapesContainer& other);
	~ShapesContainer();

	void AddShape(char* shape, double startX, double startY, const char* color, unsigned int ID, double endX, double endY=0);
	void PrintAll();
};

void ShapesContainer::Free()
{
	for (int i = 0; i < count; i++)
		delete shapes[i];

	delete[] shapes;
}
void ShapesContainer::CopyFrom(const ShapesContainer& other)
{
	shapes = new Shapes * [other.capacity];
	capacity = other.capacity;
	count = other.count;
	for (int i = 0; i < count; i++)
		shapes[i] = other.shapes[i]->clone();
}
void ShapesContainer::Resize(int NewCappacity)
{
	Shapes** NewArray = new Shapes*[NewCappacity];

	for (int i = 0; i < count; i++)
		NewArray[i] = shapes[i]->clone();

	for (int i = 0; i < count; i++)
		delete shapes[i];

	delete[] shapes;
	shapes = NewArray;
	int current = 0;
	capacity = NewCappacity;
}


ShapesContainer::ShapesContainer()
{
	capacity = 8;
	count = 0;
	shapes = new Shapes * [capacity];
}
ShapesContainer::ShapesContainer(const ShapesContainer& other)
{
	CopyFrom(other);
}
ShapesContainer& ShapesContainer::operator=(const ShapesContainer& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
ShapesContainer::~ShapesContainer()
{
	Free();
}


void ShapesContainer::AddShape(char* shape, double startX, double startY, const char* color, unsigned int ID, double endX, double endY = 0)
{
	if (count == this->capacity)
		Resize(capacity*2);
	Shapes* newObj;
	if (strcmp(shape,"line"))
	{
		newObj = new Line(startX, startY, endX, endY, color, ID);
	}
	else if (strcmp(shape, "circle"))
	{
		newObj = new Circle(startX, startY, endX, color, ID); // endX here plays the role of radius
	}
	else if (strcmp(shape, "rectangle"))
	{
		newObj = new Rectangle(startX, startY, endX, endY, color, ID); // endX and endY play the role of width and height exactly in that order
	}
	else
	{
		throw "Invalid shape";
	}
	shapes[this->count++] = newObj;
}
void ShapesContainer::PrintAll()
{
	for (int i = 0; i < count; i++)
		shapes[i]->Print(cout);
}
