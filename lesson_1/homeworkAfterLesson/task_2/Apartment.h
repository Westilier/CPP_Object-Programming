#pragma once

#include <iostream>
#include <vector>
#include <cmath>  

#include "Room.h"
#include "Roll.h"

class Apartment
{
public:
	void AddRoom(Room const& room);

	double CalculateWallpaperRequierments(std::vector<Roll> const& rools);

private:
	std::vector<Room>m_rooms;
};

