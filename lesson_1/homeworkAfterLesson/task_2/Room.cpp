#include "Room.h"

Room::Room(std::string name, double length, double width, bool wallpaperOnCelling)
	:m_name(name), m_length(length), m_width(width), m_wallpaperOnCelling(wallpaperOnCelling)
{
}

double Room::GetWallArea() const
{
	return 2 * (m_width + m_length) * 2.5;
}

double Room::GetCellingArea() const
{
	return m_width * m_length;
}

double Room::GetTotalArea() const
{
	double area = GetWallArea();

	if (m_wallpaperOnCelling)
	{
		area += GetCellingArea();
	}
	return area;
}
