#include <iostream>
#include "ShapesContainer.h"
int main()
{
    ShapesContainer array;
    array.AddShape("circle", 1, 2, "black", 2, 5.0);
    array.AddShape("line", 1, 1, "blue", 2, 3);
    array.PrintAll();
}
