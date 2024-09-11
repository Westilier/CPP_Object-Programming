#include "Point.h"

Point::Point(double x = 0, double y = 0, double z = 0)
	:m_x(x), m_y(y), m_z(z)
{
}

void Point::SaveToFile()
{
	std::fstream saveFile("Coordinates.txt");
	saveFile << "x " << m_x << std::endl << " y " << m_y << std::endl << " z " << m_z;
	saveFile.close();
}

void Point::PrintCoordinates()
{
	std::cout << "x " << m_x << std::endl << " y " << m_y << std::endl << " z " << m_z << std::endl;
}
