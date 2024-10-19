#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) :m_numerator{ numerator }
{
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
	Reduce();
}

Fraction::Fraction() :Fraction(1, 1)
{
}

void Fraction::Reduce()
{
    int nMostCommonMultiple = m_denominator;
    while (nMostCommonMultiple > 1) {
        if ((m_numerator % nMostCommonMultiple) == 0 && (m_denominator % nMostCommonMultiple) == 0)
        {
			m_numerator /= nMostCommonMultiple;
			m_denominator /= nMostCommonMultiple;
            break;
        }
        --nMostCommonMultiple;
    }
}

void Fraction::SetNumerator(int& numerator)
{
	m_numerator = numerator;
}

void Fraction::SetDenominator(int& denominator)
{
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
}

int Fraction::GetNumerator() const 
{
	return m_numerator;
}

int Fraction::GetDenominator() const 
{
	return m_denominator;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction(left.GetNumerator()*right.GetDenominator() +right.GetNumerator() *left.GetDenominator(),
		left.GetDenominator()*right.GetDenominator());
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction(left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator(),
		left.GetDenominator() * right.GetDenominator());
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	return Fraction(left.GetNumerator() * right.GetNumerator(), left.GetDenominator() * right.GetDenominator());
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return Fraction(left.GetNumerator() * right.GetDenominator(), left.GetDenominator() * right.GetNumerator());
}
std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
	return out;
}