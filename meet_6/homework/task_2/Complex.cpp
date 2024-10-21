#include "Complex.h"

Complex::Complex(double real, double imaginary) :m_real{ real }, m_imaginary{ imaginary }
{
}

Complex::Complex() :Complex(1, 1)
{
}

Complex operator+(const Complex& left, const Complex& right)
{
	return Complex(left.m_real + right.m_real, left.m_imaginary + right.m_imaginary);
}

Complex operator-(const Complex& left, const Complex& right)
{
	return Complex(left.m_real - right.m_real, left.m_imaginary - right.m_imaginary);
}

Complex operator*(const Complex& left, const Complex& right)
{
	return Complex(left.m_real * right.m_real, left.m_imaginary * right.m_real + right.m_imaginary * left.m_real);
}

Complex operator/(const Complex& left, const Complex& right)
{
	return Complex((left.m_real*right.m_real + left.m_imaginary * right.m_imaginary) / 
		(right.m_real * right.m_real + right.m_imaginary * right.m_imaginary),
		(left.m_imaginary*right.m_real -left.m_real*right.m_imaginary)/
		(right.m_real * right.m_real + right.m_imaginary * right.m_imaginary)
	);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
	if (complex.m_imaginary < 0)
	{
		out << complex.m_real << complex.m_imaginary << "i";
	}
	else
	{
		out << complex.m_real << "+" << complex.m_imaginary << "i";
	}

	return out;
}