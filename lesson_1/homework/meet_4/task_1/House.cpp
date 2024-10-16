#include "House.h"

#include "House.h"

House::House() : m_apartments{}, m_number{ 0 }
{
}

House::House(const House& House) : m_apartments{}, m_number{ 0 }
{
	m_apartments = House.m_apartments;
}

House::~House()
{
	m_apartments.clear();
}

void House::AddApartment(const Apartment& apartment)
{
	m_apartments.push_back(apartment);
}

void House::Print()
{
	std::cout << "Дом " << m_number << std::endl;
	for (size_t i = 0; i < m_apartments.size(); i++)
	{
		m_apartments[i].Print();
	}
}
