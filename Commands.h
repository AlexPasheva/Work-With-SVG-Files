#pragma once
#include "ShapesContainer.h"

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
void Print(ShapesContainer array)
{
	array.PrintAll();
}
Shapes* CreateShapes(ShapesContainer array, char* shape, double startX, double startY, const char* color, double endX, double endY = 0)
{
	array.AddShape(shape, startX, startY, color, endX, endY);
}
void TranslateShape(ShapesContainer& array, double vertical, double horizontal, int n = -1)
{                                                                                                
	if (n == -1)
	{
		for (int i = 0; i < array.GetCapacity(); i++)
		{
			array.AtIndex(i)->Translate(vertical,horizontal);
		}
	}
	else
	{
		array.AtIndex(n)->Translate(vertical, horizontal);
	}
}
void WithinShape(ShapesContainer& array, double startX, double startY, double width, double height = 0)
{
	if (height == 0)
	{
		for (int i = 0; i < array.GetCapacity(); i++)
			array.AtIndex(i)->WithinCircle(startX, startY, width);
	}
	else
	{
		for (int i = 0; i < array.GetCapacity(); i++)
			array.AtIndex(i)->WhitinRectangle(startX, startY, width, height);
	}
}
void EraseShape(ShapesContainer& array, int index)
{
	array.Erase(index);
}
