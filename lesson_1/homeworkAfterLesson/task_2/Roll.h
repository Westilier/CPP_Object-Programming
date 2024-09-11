#pragma once
#include <string>

class Roll
{
public:
	Roll(std::string const& name, double height, double width, double price);

	double GetArea() const;

	std::string GetName() const;

	double GetPrice() const;

private:
	std::string m_name;
	double m_height;
	double m_width;
	double m_price;
};

