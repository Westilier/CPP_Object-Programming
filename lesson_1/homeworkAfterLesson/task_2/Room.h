#pragma once
#include <string>

class Room
{
public:
	Room(std::string name, double length, double width,bool wallpaperOnCelling);

	double GetWallArea()const;

	double GetCellingArea() const;

	double GetTotalArea() const;

private:

	std::string m_name;
	double m_length, m_width;
	bool m_wallpaperOnCelling;
};

