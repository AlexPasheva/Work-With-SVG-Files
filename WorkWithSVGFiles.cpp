#include <iostream>
#include "SVGParser.h"
int MAXLEN = 256;
int main()
{
	ifstream input;
	ShapesContainer array;
	char* CommandLine=new char[MAXLEN];
	char* command=new char[MAXLEN];
	char* shape=new char[MAXLEN];
	char* color = new char[MAXLEN];
	char* filename = new char[MAXLEN];
	int startX = 0, startY = 0, endX = 0, endY = 0;

	while(1)
	{
		cout << "Enter command:"<<endl;

		cin.getline(command,100);

		if (strcmp(command,"print")==0)
		{
			array.PrintAll();
		}
		else if (strcmp(command, "create")==0)
		{
			cout << "Enter shape:"<<endl;
			cin.getline(shape, 100);

			if (strcmp(shape, "rectangle") == 0)
			{
				cout << "Enter parameters:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				cin >> endY;
				cin.ignore(1);
				cin.getline(color, 100);
				array.AddShape("rectangle", startX, startY, color, endX, endY);
			}
			else if (strcmp(command,"circle") == 0 )
			{
				cout << "Enter parameters:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				cin.ignore(1);
				cin.getline(color, 100);
				array.AddShape("circle", startX, startY, color, endX);
			}
			else if (strcmp(command,"line") == 0)
			{
				cout << "Enter parameters:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				cin >> endY;
				cin.ignore(1);
				cin.getline(color, 100);
				array.AddShape("line", startX, startY, color, endX, endY);
			}
			else
			{
				cout << "Shape not supported.";
			}
		}
		else if (strcmp(command, "translate") == 0)
		{//очаква команда във формат първо vertical=10 или 4 vertical=10 /нов ред/ horizontal=20
			int n = 0;
			int h = 0;
			int v = 0;
			char* horizontal = new char[30];
			char* vertical = new char[30];
			char* number = new char[15];
			cin.getline(vertical, 30);
			int i = 0;
			while (vertical[i] >= 0 && vertical[i] <= 9)
			{
				number[i] = vertical[i];
				i++;
			}
			n = atoi(number);
			i = 0;
			int j = 9;
			while (vertical[j] >= 0 && vertical[j] <= 9)
			{
				number[i] = vertical[j];
				i++;
				j++;
			}
			v = atoi(number);
			cin.getline(horizontal, 30);
			i = 0;
			j = 11;
			while (horizontal[j] >= 0 && horizontal[j] <= 9)
			{
				number[i] = horizontal[j];
				i++;
				j++;
			}
			h = atoi(number);
			if (n == 0)
			{
				array.TranslateShape(v, h);
			}
			array.TranslateShape(v, h, n);
			delete[] vertical;
			delete[] horizontal;
			delete[] number;
		}
		else if (strcmp(command, "within") == 0)
		{
			cout << "Enter shape:" << endl;
			cin.getline(shape, 100);
			if (strcmp(shape, "rectangle") == 0)
			{
				cout << "Enter parameters:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				cin >> endY;
				array.WithinRectangle(startX, startY, endX, endY);
			}
			else if (strcmp(shape, "circle") == 0)
			{
				cout << "Enter parameters:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				array.WithinCircle(startX, startY, endX);
			}
			else
			{
				cout << "Shape not supported.";
			}
		}
		else if (strcmp(command, "open") == 0)
		{
			cout << "Enter file name:" << endl;
			cin.getline(filename, 100);
			input.open(filename);
			if (!input.is_open())
			{
				cout << "Couldn't open the file.";
			}
			array=ParseFile(filename);
		}
		else if (strcmp(command, "close") == 0)
		{
			input.close();
		}
		else if (strcmp(command,"save as")==0)
		{
			cout << "Enter svg file name:" << endl;
			cin.getline(shape, 100);
			WritingBackInSVGFile(shape, array);
			remove(shape);
			rename("temp.svg", shape);
		}
		else if (strcmp(command, "save") == 0)
		{
			WritingBackInSVGFile(filename, array);
			remove(filename);
			rename("temp.svg", filename);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "help") == 0)
		{
			Help();
		}
	}
	delete[] CommandLine;
	delete[] command;
	delete[] shape;
	delete[] color;
	delete[] filename;
}


