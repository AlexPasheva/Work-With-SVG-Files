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
	int currsor=LinesCount(filename);//the total lines in the file
	ifstream input;
	string line;                     // I'm using that string to get rid of chars I do not need
	string token = "<svg>";
	input.open(filename);
	unsigned int curLine = 0;
	while (getline(input, line))     // curLine is the index of the start of the <svg> tag
	{
		curLine++;
		if (line.find(token, 0) != string::npos) 
		{
			break;
		}
	}                                // I'm finding curLine by searching for the <svg> tag

	string shape;
	int LinesLeft = currsor - curLine + 1;
	int startX = 0, startY = 0, endX = 0, endY = 0;
	string line2;
	string color;

	input.seekg(0);

	for (int n = 1; n < curLine; n += 1) // skipping the first lines before the opening tag
	{
		if (!getline(input, line2)) 
		{
			cout << "error";
		}
	}
	while (getline(input, line2))    //building the Container
	{
		if (LinesLeft==currsor)
		{
			break;                   // I break before the closing </svg> tag
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

	return array;
}
void WritingBackInSVGFile(const char* filename, ShapesContainer& array)// this function is building new svg file with changed information
{
	ofstream ofs;
	ofs.open("temp.svg", ofstream::out);// using this file to build the whole file changing only the <svg> tagged section
	int currsor = LinesCount(filename);//the total lines in the file
	ifstream input;
	string line;                     // I'm using that string to get rid of chars I do not need
	string token = "<svg>";
	input.open(filename);
	unsigned int curLine = 0;
	while (getline(input, line))     // curLine is the index of the start of the <svg> tag
	{
		curLine++;
		if (line.find(token, 0) != string::npos)
		{
			break;
		}
	}                                // I'm finding curLine by searching for the <svg> tag
	input.seekg(0);
	int LinesLeft = currsor - curLine + 1;
	for (int i = 0; i < curLine; i++)
	{
		getline(input, line);
		ofs << line << endl;
	}
	array.PrintAllInStrm(ofs);
	ofs << "</svg>";
}
