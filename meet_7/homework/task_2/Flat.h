#pragma once

class Flat
{
public:
	Flat(double square, size_t price);
	Flat();

	Flat& operator=(const Flat& other);

	bool operator== (const Flat& other) const;
	bool operator> (const Flat& other) const;

private:
	double m_square;
	size_t m_price;
};


