#pragma once
#include<iostream>

class Date
{
public:
	Date(long day, long month, long year);
	Date();

	Date& operator=(const Date& other);
	void operator++();
	void operator--();

	friend bool operator==(const Date& left, const Date& right);
	friend bool operator!=(const Date& left, const Date& right);


	friend Date operator+(const Date& left, const int& right);
	friend Date operator-(const Date& left, const int& right);

	friend void operator+=(Date& left, const int& right);
	friend void operator-=(Date& left, const int& right);

	friend bool operator>(const Date& left, const Date& right);
	friend bool operator<(const Date& left, const Date& right);
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);

private:
	friend bool IsYearLeap(long year);
	friend int GetdaysToMonth(int nMonth, bool isLeapYear);

	long m_day;
	long m_month;
	long m_year;
};

