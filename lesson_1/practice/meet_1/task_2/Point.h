#pragma once

#include <iostream>
#include <fstream>

class Point
{
public:
	Point(double x = 0, double y = 0, double z = 0);

	void SaveToFile();

	void PrintCoordinates();

	void SetX(double x);
	void SetY(double x);
	void SetZ(double x);

	double GetX(double x);
	double GetY(double x);
	double GetZ(double x);

private:
	double m_x;
	double m_y;
	double m_z;
};

