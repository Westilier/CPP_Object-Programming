#pragma once
#include<iostream>

class Complex
{
public:
	Complex(double real, double imaginary);
	Complex();

	friend Complex operator+(const Complex& left, const Complex& right);
	friend Complex operator-(const Complex& left, const Complex& right);
	friend Complex operator*(const Complex& left, const Complex& right);
	friend Complex operator/(const Complex& left, const Complex& right);

	friend std::ostream& operator<<(std::ostream& out, const Complex& Complex);
private:
	double m_real;
	double m_imaginary;
};

