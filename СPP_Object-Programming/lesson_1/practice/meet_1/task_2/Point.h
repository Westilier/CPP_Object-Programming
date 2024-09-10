#pragma once

class Point
{
public:
	Point(double& x, double& y, double& z);

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

