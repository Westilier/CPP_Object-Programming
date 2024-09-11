#include "Roll.h"

Roll::Roll(std::string const& name, double height, double width, double price)
	:m_name(name), m_height(height), m_width(width), m_price(price)
{
}

double Roll::GetArea() const
{
    return m_height*m_width;
}

std::string Roll::GetName() const
{
	return m_name;
}

double Roll::GetPrice() const
{
	return m_price;
}

