
#include "Rectangle.h"
class ShapesContainer
{
private:
	Shapes** shapes;

	int capacity;
	int count;

	void CopyFrom(const ShapesContainer& other);
	void Free();
	void Resize(int NewCappacity);

public:
	ShapesContainer();
	ShapesContainer(const ShapesContainer& other);
	ShapesContainer& operator=(const ShapesContainer& other);
	~ShapesContainer();

	int GetCount();

	Shapes* AtIndex(int index);
	void AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY=0);
	void PrintAllInStrm(ostream& strm);
	void PrintAll();
	void Erase(int index);
	void WithinCircle(double startX, double startY, double radius);
	void WithinRectangle(double startX, double startY, double width, double height);
	void TranslateShape(double vertical, double horizontal);
	void TranslateShape(double vertical, double horizontal, int n);
};
