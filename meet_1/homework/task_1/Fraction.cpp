#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	m_numerator = numerator;
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
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

void Fraction::Add(Fraction fraction)
{
	if (m_denominator == fraction.GetDenominator())
	{
        m_numerator += fraction.GetNumerator();
	}
	else
	{
        m_numerator = m_numerator * fraction.GetDenominator() + fraction.GetNumerator() * m_denominator;
        m_denominator *= fraction.GetDenominator();  
	}
}

void Fraction::Subtract(Fraction fraction)
{
	if (m_denominator == fraction.GetDenominator())
	{
		m_numerator -= fraction.GetNumerator();
	}
	else
	{
		m_numerator = m_numerator * fraction.GetDenominator() - fraction.GetNumerator() * m_denominator;
		m_denominator *= fraction.GetDenominator();
	}
}

void Fraction::Multiply(Fraction fraction)
{
	m_numerator *= fraction.GetNumerator();
	m_denominator *= fraction.GetDenominator();
}

void Fraction::Divide(Fraction fraction)
{
	m_numerator *=  fraction.GetDenominator();
	m_denominator *= fraction.GetNumerator();
}

void Fraction::SetNumerator(int numerator)
{
	m_numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
}

int Fraction::GetNumerator()
{
	return m_numerator;
}

int Fraction::GetDenominator()
{
	return m_denominator;
}

