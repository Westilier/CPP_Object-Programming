#pragma once
#include <iostream>

class Fraction
{
public:
	Fraction(int numerator, int denominator);

	Fraction();

	void SetNumerator(int& numerator);
	void SetDenominator(int& denominator);

	int GetNumerator() const;
	int GetDenominator() const;


	friend Fraction operator+(const Fraction& left, const Fraction& right);
	friend Fraction operator-(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const Fraction& right);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
private:
	int m_numerator;
	int m_denominator;
	void Reduce();
};

