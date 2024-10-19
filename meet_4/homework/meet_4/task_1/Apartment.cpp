#include "Apartment.h"

Apartment::Apartment() :m_humans{}, m_number{ 0 }
{
}

Apartment::Apartment(const Apartment& apartment) : m_humans{ apartment.m_humans }, m_number{ apartment.m_number }
{
}

Apartment::~Apartment()
{
	m_humans.clear();
}

Apartment& Apartment::operator=(const Apartment& other)
{
	if (this != &other)
	{
		m_humans = other.m_humans;
		m_number = other.m_number;
	}
	return *this;
}

void Apartment::AddHuman(Human const& human)
{
	m_humans.push_back(human);
}

void Apartment::Print()
{
	std::cout << " вартира " << m_number << std::endl;
	for (size_t i = 0; i < m_humans.size(); i++)
	{
		m_humans[i].Print();
	}
}

void Apartment::Input(Human human, size_t apartmentNumber)
{
	m_humans.push_back(human);
	m_number = number;
}
