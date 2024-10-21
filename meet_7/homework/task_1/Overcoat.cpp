#include "Overcoat.h"

Overcoat::Overcoat(std::string type, size_t price) : m_type{ type }, m_price{ price }
{
}

Overcoat::Overcoat() :Overcoat("Notype", 0)
{
}

Overcoat& Overcoat::operator=(const Overcoat& other)
{
	if (this != &other)
	{
		m_type = other.m_type;
		m_price = other.m_price;
	}
	return *this;
}

bool Overcoat::operator==(const Overcoat& other) const
{
	return (m_type == other.m_type);
}

bool Overcoat::operator>(const Overcoat& other) const
{
	return (m_price > other.m_price);
}
