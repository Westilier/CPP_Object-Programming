#include "Apartment.h"


void Apartment::AddRoom(Room const& room)
{
	m_rooms.push_back(room);
}
double Apartment::CalculateWallpaperRequierments(std::vector<Roll> const& rolls)
{
	for (const Roll& roll : rolls)
	{
		double totalRollArea = 0;
		for (const Room& room : m_rooms)
		{
			totalRollArea += room.GetTotalArea();
		}

		double rollArea = roll.GetArea();

		size_t requiresRools = ceil(totalRollArea / rollArea);

		std::cout << "для " << roll.GetName() << "нужно " << requiresRools << "рулонов по цене" << roll.GetPrice();
	}
}

