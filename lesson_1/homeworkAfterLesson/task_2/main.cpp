#include <iostream>

#include "Apartment.h";
#include "Room.h";
#include "Roll.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "rus");
	size_t numberOfRooms;
	std::cout << "������� ���-�� ������: ";
	std::cin >> numberOfRooms;

	Apartment aparment;

	for (size_t i = 0; i < numberOfRooms; i++)
	{
		std::string name;
		double length, width;
		bool wallpaperOnCelling;

		std::cout << "������� �������� ������� " << (i + 1) << ": ";
		std::cin >> name;

		std::cout << "������ ����� ������� (� ������): ";
		std::cin >> length;

		std::cout << "������ ������ ������� (� ������): ";
		std::cin >> width;

		std::cout << "������ �������? (1 - ��, 0 - ���): ";
		std::cin >> wallpaperOnCelling;


		Room room(name, length, width, wallpaperOnCelling);
		aparment.AddRoom(room);
	}

	size_t numberOfRolls;
	std::cout << "������� ���-�� ����� �������: ";
	std::cin >> numberOfRolls;

	std::vector<Roll> rolls;
	for (size_t i = 0; i < numberOfRolls; i++)
	{
		std::string name;
		double height, width, price;

		std::cout << "������ �������� ����� " << (i + 1) << ": ";
		std::cin >> name;

		std::cout << "������ ����� ������ (� ������): ";
		std::cin >> height;

		std::cout << "������ ������ ������ (� ������): ";
		std::cin >> width;

		std::cout << "������� ���� ������: ";
		std::cin >> price;

		Roll roll(name, height, width, price);
		rolls.push_back(roll);
	}

	aparment.CalculateWallpaperRequierments(rolls);
}