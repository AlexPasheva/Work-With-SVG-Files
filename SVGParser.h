#pragma once
#include "ShapesContainer.h"
#include <string>
void Open(string filename)
{
	ifstream input;
	input.open(filename);
	if (!input.is_open())
	{
		cout << "Couldn't open the file.";
	}
}
int LinesCount(string filename)
{
	ifstream input;
	input.open(filename);
	string line;
	unsigned int curLine = 0;
	while (getline(input, line))
	{
		curLine++;
	}
	input.close();
	return curLine;
}
ShapesContainer ParseFile(string filename)
{
	ShapesContainer array;
	int currsor=LinesCount(filename);
	ifstream input;
	string line;
	string helper;
	string token = "<svg>";
	input.open(filename);
	unsigned int curLine = 0;
	while (getline(input, line)) 
	{
		curLine++;
		if (line.find(token, 0) != string::npos) {
			cout << "found: " << token << "line: " << curLine << endl;
			break;
		}
	}
	string shape;
	string line2;
	int LinesLeft = currsor - curLine + 1;
	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	char color1[50];
	string color;
	input.seekg(0);
	for (int n = 1; n < curLine; n += 1) 
	{
		if (!getline(input, line2)) 
		{
			cout << "error";
		}
	}
	while (getline(input, line2)) 
	{
		if (LinesLeft==currsor)
		{
			break;
		}

		input.ignore(3);
		getline(input, shape, ' ');
		if (shape.compare("rect") == 0)
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			input >> endY;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			array.AddShape("rectangle", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		else if(shape.compare("circle")==0)
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			array.AddShape("circle", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		else if (shape.compare("line"))
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			input >> endY;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			array.AddShape("line", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		LinesLeft++;
	}

	array.PrintAll();
	return array;
}
