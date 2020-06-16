
#include "Line.h"
class Circle : public Shapes
{
private:
	double radius;
public:
	Circle(double centerX = 0, double centerY = 0, double radius = 0, const char* color = "Unidentified", unsigned int ID = 0);


	//Getters and setters
	double GetRadius();
	void SetRadius(double radius);


	//Some methods
	void Print(ostream& strm);
	void Print();
	void Translate(double horizontal, double vertical);
	bool IsWithinRectangle(double startX, double startY, double width, double height);
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	Shapes* clone();
};
