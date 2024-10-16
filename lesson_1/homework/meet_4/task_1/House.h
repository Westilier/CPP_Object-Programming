#pragma once
#include<vector>

#include"Apartment.h"

class House
{
public:
	House();

	House(const House& apartment);
	~House();

	void AddApartment(const Apartment& Apartment);
	void Print();
private:
	std::vector<Apartment> m_apartments;
	size_t m_number;
};

