#include "Point.h"
class Shapes
{
protected:
	Point start;
	char color[25];
	unsigned int ID;
public:
	Shapes(double x = 0, double y = 0, const char* color = "Unidentified", unsigned int ID = 0);


	//Getters and setters
	char* GetColor();
	unsigned int GetID();
	Point GetStart();
	void SetColor(char* color);
	void SetID(unsigned int ID);


	//Some Methods that are overwritten for different objects
	virtual void Print(ostream& strm) = 0;
	virtual void Print()=0;
	virtual void Translate(double vertical, double horizontal)=0;
	virtual bool WithinRectangle(double startX, double startY, double width, double height)=0;
	virtual bool WithinCircle(double startX, double startY, double radius)=0;
	virtual double Area(double width, double height);
	virtual ~Shapes();

	virtual Shapes* clone()=0;
};
