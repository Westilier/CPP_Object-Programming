#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Point
{
public:
	Point(int x = 0, int y = 0, int z = 0);

	void SaveToFile(std::string pathToFile);
	void LoadFromFile(std::string pathToFile);

	void PrintCoordinates();

	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);

	int GetX();
	int GetY();
	int GetZ();

private:
	int m_x;
	int m_y;
	int m_z;
};

