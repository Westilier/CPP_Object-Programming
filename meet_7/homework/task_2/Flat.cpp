#include "Flat.h"

Flat::Flat(double square, size_t price) : m_square{ square }, m_price{ price }
{
}

Flat::Flat() :Flat(0, 0)
{
}

Flat& Flat::operator=(const Flat& other)
{
	if (this != &other)
	{
		m_square = other.m_square;
		m_price = other.m_price;
	}
	return *this;
}

bool Flat::operator==(const Flat& other) const
{
	return (m_square == other.m_square);
}

bool Flat::operator>(const Flat& other) const
{
	return (m_price > other.m_price);
}
