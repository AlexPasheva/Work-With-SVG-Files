#pragma once
#include "Shapes.h"

void Help()
{
	cout << "The following commands are supported:" << endl <<
		"open <file>	  opens <file>" << endl <<
		"close			  closes currently opened file" << endl <<
		"save			  saves the currently open file" << endl <<
		"saveas <file>	  saves the currently open file in <file>" << endl <<
		"help			  prints this information" << endl <<
		"exit			  exists the program" << endl <<
		"print            prints all shapes" << endl <<
		"create           creates new shape" << endl <<
		"erase <n>        erases the nth shape" << endl <<
		"translate [<n>]  transaltes the nth shape or if n is not given, translates all shapes" << endl <<
		"whitin <option>  prints all shapes in that region" << endl ;
}
void Print(Shapes* array, int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		array[i].Print(cout);
	}
}
Shapes* CreateShapes(Shapes* array, int ArraySize, char* shape)
{
	Shapes* NewArray = new Shapes[ArraySize + 1];
	if (strcmp(shape,"line")==0)
	{
		double startY, startX, endX, endY;
		cin >> startY >> startX >> endX >> endY;
		char color[25];
		cin.getline(color, 25);
		int ID;
		cin >> ID;
		Line line;
		NewArray= line.Create(array, ArraySize, startX, startY, endX, endY, color, ID);
	}
	else if (strcmp(shape, "circle") == 0)
	{
		double startY, startX, radius;
		cin >> startY >> startX >> radius;
		char color[25];
		cin.getline(color, 25);
		int ID;
		cin >> ID;
		Circle circle;
		NewArray = circle.Create(array, ArraySize, startX, startY, radius, color, ID);
	}
	else if (strcmp(shape, "rectangle") == 0)
	{
		double startY, startX, width, height;
		cin >> startY >> startX >> width >> height;
		char color[25];
		cin.getline(color, 25);
		int ID;
		cin >> ID;
		Rectangle rectangle;
		NewArray = rectangle.Create(array, ArraySize, startX, startY, width , height, color, ID);
	}
	else
	{
		cout << "We can't create that shape at the moment.";
		return;
	}
	return NewArray;
}
//Shapes* shapeCollection[10] ;
//shapeCollection[0] = new Circle(parameters);
void TranslateShape(Shapes* array, int ArraySize, double vertical, double horizontal, int n = -1)//this function works with array like the one above
{                                                                                                // it may work better with std container tho
	if (n == -1)
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
void WithinShape(Shapes* array, int ArraySize, double startX, double startY, double width, double height = 0)
{
	if (height == 0)
	{
		for (int i = 0; i < ArraySize; i++)
			array[i].WithinCircle(startX, startY, width);
	}
	else
	{
		for (int i = 0; i < ArraySize; i++)
			array[i].WhitinRectangle(startX, startY, width, height);
	}
}
