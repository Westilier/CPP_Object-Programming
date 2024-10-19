#include "Point.h"


Point::Point(int x, int y, int z)
	:m_x(x), m_y(y), m_z(z)
{
}

void Point::SaveToFile(std::string pathToFile)
{
	std::ofstream saveFile(pathToFile);
	saveFile << "x " << m_x << std::endl << "y " << m_y << std::endl << "z " << m_z;
	saveFile.close();
}

void Point::LoadFromFile(std::string pathToFile)
{
	std::ifstream saveFile(pathToFile);
	std::string line;
	while (std::getline(saveFile, line))
	{
		if (line.find("x") != std::string::npos)
		{
			m_x = stoi(line.erase(0, 2));
		}
		else if (line.find("y") != std::string::npos)
		{
			m_y = stoi(line.erase(0, 2));
		}
		else if (line.find("z") != std::string::npos)
		{
			m_z = stoi(line.erase(0,2));
		}
	}
	saveFile.close();
}

void Point::PrintCoordinates()
{
	std::cout << "x " << m_x << std::endl << "y " << m_y << std::endl << "z " << m_z << std::endl;
}

void Point::SetX(int x)
{
	m_x = x;
}

void Point::SetY(int y)
{
	m_y = y;
}

void Point::SetZ(int z)
{
	m_z = z;
}

int Point::GetX()
{
	return m_x;
}

int Point::GetY()
{
	return m_y;
}

int Point::GetZ()
{
	return m_z;
}
