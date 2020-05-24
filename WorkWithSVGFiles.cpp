#include <iostream>
#include "SVGParser.h"
int main()
{
	ShapesContainer array;
	ifstream input;

	char* CommandLine=new char[256];
	char* command=new char[256];
	char* shape=new char[256];
	char* color = new char[256];
	char* filename = new char[256];
	int vertical=0, horizontal=0;
	int startX = 0, startY = 0, endX = 0, endY = 0;
	//string color;
	while(1)
	{
		cout << "Enter command"<<endl;

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
		{

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
		}
		else if (strcmp(command, "save") == 0)
		{
			WritingBackInSVGFile(filename, array);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
	}
}

