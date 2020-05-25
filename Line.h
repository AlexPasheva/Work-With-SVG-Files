
#include "Shapes.h"
class Line : public Shapes
{
private:
	Point end;
public:
	Line(double startX = 0, double startY = 0, double endX = 0, double endY = 0, const char* color = "Unidentified", unsigned int ID = 0);

	Point GetEnd();


	//Some Methods
	void Translate(double vertical, double horizontal);
	void Print(ostream& strm);
	void Print();
	bool WithinRectangle(double startX, double startY, double width, double height);
	bool WithinCircle(double startX, double startY, double radius);

	Line* clone();
};