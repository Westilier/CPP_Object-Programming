#include "Apartment.h"

Apartment::Apartment() : m_size{ 0 }, m_humans{ new Human[m_size] }, m_number{ 0 }
{
}

Apartment::Apartment(size_t size) : m_size{ size }, m_humans{ new Human[size] }, m_number{ 0 }
{
}

Apartment::Apartment(Apartment& apartment) : m_humans{ new Human[apartment.m_size] }, m_size{ apartment.m_size }, m_number{ apartment.m_number }
{
	for (int i = 0; i < m_size; ++i)
	{
		m_humans[i] = apartment.m_humans[i];
	};
}

Apartment::~Apartment()
{
	m_humans = nullptr;
	m_size = 0;
}

Apartment& Apartment::operator=(const Apartment& other)
{
	if (this != &other)
	{
		m_humans = new Human[other.m_size];
		m_size = other.m_size;
		m_number = other.m_number;
		for (int i = 0; i < m_size; ++i)
		{
			m_humans[i] = other.m_humans[i];
		};
	}
	return *this;
}

void Apartment::AddHuman(Human human)
{
	m_size += 1;
	m_humans[m_size-1] = human ;
}

void Apartment::Print()
{
	std::cout << " вартира " << m_number << std::endl;
	for (size_t i = 0; i < m_size; i++)
	{
		m_humans[i].Print();
	}
}

void Apartment::Input(Human human, size_t number)
{
	m_size += 1;
	m_humans[m_size-1] = human;
	m_number = number;
}
