#pragma once
class Fraction
{
public:
	Fraction(int numerator, int denominator);

	void Reduce();

	void Add(Fraction fraction);
	void Subtract(Fraction fraction);
	void Multiply(Fraction fraction);
	void Divide(Fraction fraction);

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	int GetNumerator();
	int GetDenominator();

private:
	int m_numerator;
	int m_denominator;
};

