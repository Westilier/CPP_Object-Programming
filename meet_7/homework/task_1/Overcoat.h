#pragma once
#include<string>

class Overcoat
{
public:
	Overcoat(std::string type, size_t price);
	Overcoat();

	Overcoat& operator=(const Overcoat& other);

	bool operator== (const Overcoat& other) const;
	bool operator> (const Overcoat& other) const;

private:
	std::string m_type;
	size_t m_price;
};

