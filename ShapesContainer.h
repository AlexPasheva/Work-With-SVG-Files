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
