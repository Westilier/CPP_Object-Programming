#include "House.h"

#include "House.h"

House::House() : m_size{ 0 }, m_apartments{ new Apartment[m_size] {} }, m_number{ 0 }
{
}

House::House(const House& House) : m_apartments{ new Apartment[House.m_size] }, m_size{ House.m_size }, m_number{ House.m_number}
{
	for (int i = 0; i < m_size; ++i)
	{
		m_apartments[i] = House.m_apartments[i];
	};
}

House::~House()
{
	m_apartments = nullptr;
	m_size = 0;
}

void House::AddApartment(const Apartment& apartment)
{
	Apartment* tempApartments = new Apartment[m_size + 1];
	
	for (size_t i = 0; i < m_size - 1; i++)
	{
		tempApartments[i] = m_apartments[i];
	}
	delete[] m_apartments;
	tempApartments[m_size] = apartment;
	m_apartments = tempApartments;
}

void House::Print()
{
	std::cout << "Дом " << m_number << std::endl;
	for (size_t i = 0; i < m_size; i++)
	{
		m_apartments[i].Print();
	}
}
