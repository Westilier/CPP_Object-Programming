#pragma once

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
	Apartment* m_apartments;
	size_t m_size;
	size_t m_number;
};

