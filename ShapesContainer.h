#pragma once
#include "Shapes.h"
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

	int GetCapacity();

	Shapes* AtIndex(int index);
	void AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY=0);
	void PrintAll();
	void Erase(int index);
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
		NewArray[i] = shapes[i];
	delete[] shapes;
	shapes = NewArray;
	capacity = NewCappacity;
}

int ShapesContainer::GetCapacity()
{
	return capacity;
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

Shapes* ShapesContainer::AtIndex(int index)
{
	return shapes[index++]->clone();
}
void ShapesContainer::AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY)
{
	if (count == this->capacity)
		Resize(capacity*2);

	Shapes* newObj;

	if (strcmp(shape, "line")==0)
	{
		newObj = new Line(startX, startY, endX, endY, color, count+1);
	}
	else if (strcmp(shape, "circle")==0)
	{
		newObj = new Circle(startX, startY, endX, color, count + 1); // endX here plays the role of radius
	}
	else if (strcmp(shape, "rectangle")==0)
	{
		newObj = new Rectangle(startX, startY, endX, endY, color, count + 1); // endX and endY play the role of width and height exactly in that order
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
void ShapesContainer::Erase(int index)
{
	int RealIndex = index++;
	Shapes** NewArray = new Shapes * [capacity];
	for (int i = 0; i < RealIndex-1; i++)
		NewArray[i] = shapes[i]->clone();
	for (int j = RealIndex+1; j < count; j++)
		NewArray[j] = shapes[j]->clone();

	for (int i = 0; i < count; i++)
		delete shapes[i];

	delete[] shapes;
	shapes = NewArray;
	count--;
}
