#include "Date.h"

bool IsYearLeap(long year)
{
	if (year % 4 && (year % 100 == 0 ? (year % 400 == 0 ? true : false) : true))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date::Date(long day, long month, long year)
{
	const long MONTH_PER_YEAR = 12,
		DAY_PER_FEBRARY_IN_LEAP_YEAR = 29, DAY_PER_FEBRARY_IN_NOT_LEAP_YEAR = 28,
		DAY_PER_ODD_MONTH = 31, DAY_PER_EVEN_MONTH_BUT_FEBRARY = 30;

}

Date::Date() :m_year{ 1970 }, m_month{ 1 }, m_day{ 1 }
{
}

Date& Date::operator=(const Date& other)
{
	if (&other != this)
	{
		m_day = other.m_day;
		m_month = other.m_month;
		m_year = other.m_year;
	}
	return *this;
}

void Date::operator++()
{
	m_day++;
}

void Date::operator--()
{
	m_day--;
	if (m_day <= 0)
	{
		if (IsYearLeap(m_year))
		{
			m_day += 366;
		}
		else
		{
			m_day += 365;
		}
		m_year--;
	}
}

bool operator==(const Date& left, const Date& right)
{
	if (left.m_day == right.m_day &&
		left.m_month == right.m_month &&
		left.m_year == right.m_year)
	{
		return true;
	}
	return false;
}

bool operator!=(const Date& left, const Date& right)
{
	if (left.m_day != right.m_day &&
		left.m_month != right.m_month &&
		left.m_year != right.m_year)
	{
		return true;
	}
	return false;
}

Date operator+(const Date& left, const Date& right)
{
	long day, month, year;
	day = left.m_day + right.m_day;
	month = left.m_month + right.m_month;
	year = left.m_year + right.m_year;
	return Date(day, month, year);
}

Date operator-(const Date& left, const Date& right)
{
	long day, month, year;
	day = left.m_day - right.m_day;
	month = left.m_month - right.m_month;
	year = left.m_year - right.m_year;
	return Date(day, month, year);
}

void operator+=(Date& left, const Date& right)
{
	left = (left + right);
}
void operator-=(Date& left, const Date& right)
{
	left = (left - right);
}

bool operator>(const Date& left, const Date& right)
{
	if (left.m_day > right.m_day &&
		left.m_month > right.m_month &&
		left.m_year > right.m_year)
	{
		return true;
	}
	return false;
}

bool operator<(const Date& left, const Date& right)
{
	if (left.m_day < right.m_day &&
		left.m_month < right.m_month &&
		left.m_year < right.m_year)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.m_day << "." << date.m_month << "." << date.m_year;
	return out;
}
std::istream& operator>>(std::istream& in, Date& date)
{
	long day, month, year;
	in >> day >> month >> year;
	date = Date(day, month, year);
	return in;
}

