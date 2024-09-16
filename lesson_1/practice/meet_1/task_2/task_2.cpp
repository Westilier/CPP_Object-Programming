#include "Point.h"

int main()
{
	Point point(1, 2);
	point.PrintCoordinates();

	//point.SaveToFile("1.txt");
	point.LoadFromFile("1.txt");

	point.PrintCoordinates();
}
