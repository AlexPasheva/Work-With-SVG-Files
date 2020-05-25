#include "Circle.h"
class Rectangle : public Shapes
{
private:
	double width;
	double height;
public:
	Rectangle(double FirstPointX = 0, double FirstPointY = 0, double width = 0, double height = 0, const char* color = "Unidentified", unsigned int ID = 0);
	//Getters and Setters
	double GetWidth();
	double GetHeight();
	void SetWidth(double width);
	void SetHeight(double height);
	//Some methods
	void Print(ostream& strm);
	void Print();
	void Translate(double horizontal, double vertical);
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	virtual Rectangle* clone();
};