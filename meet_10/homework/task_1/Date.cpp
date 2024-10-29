#include "Date.h"

bool IsYearLeap(long year)
{
	if ((year % 4 == 0) && (year % 100 == 0 ? (year % 400 == 0 ? true : false) : true))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GetdaysToMonth(int nMonth,bool isLeapYear)
{
	const int DAY_PER_FEBRARY_IN_LEAP_YEAR = 29, DAY_PER_FEBRARY_IN_NOT_LEAP_YEAR = 28,
		DAY_PER_ODD_MONTH = 31, DAY_PER_EVEN_MONTH_BUT_FEBRARY = 30;

	int countDays = 0;
	for (size_t i = 1; i <= nMonth; i++)
	{
		if (i == 2)
		{
			if (isLeapYear)
			{
				countDays += DAY_PER_FEBRARY_IN_LEAP_YEAR;
			}
			else
			{
				countDays += DAY_PER_FEBRARY_IN_NOT_LEAP_YEAR;
			}
		}
		else if (i % 2 == 0)
		{
			countDays += DAY_PER_EVEN_MONTH_BUT_FEBRARY;
		}
		else
		{
			countDays += DAY_PER_ODD_MONTH;
		}
	}
	return countDays;
}

Date::Date(long day, long month, long year)
{
	while (day <= 0)
	{
		year--;
		if (IsYearLeap(year))
		{
			day += 366;
		}
		else
		{
			day += 365;
		}
	}
	if ((IsYearLeap(year) && day > 29) || (!IsYearLeap(year) && day > 28))
	{
		month += day / 30.43375;
		m_day = day - GetdaysToMonth(day / 30.43375, IsYearLeap(year));
	}
	else
	{
		m_day = day;
	}
	while(month <= 0)
	{
		year--;
		month += 12;
	}
	if (month > 12)
	{
		m_month = (month % 12) + 1;
	}
	else
	{
		m_month = month;
	}
	m_year = year;

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

Date operator+(const Date& left, const int& right)
{
	long day;
	day = left.m_day + right;
	return Date(day, left.m_month, left.m_year);
}

Date operator-(const Date& left, const int& right)
{
	long day;
	day = left.m_day - right;
	return Date(day, left.m_month,left.m_year);
}

void operator+=(Date& left, const int& right)
{
	left = (left + right);
}
void operator-=(Date& left, const int& right)
{
	left = (left - right);
}

bool operator>(const Date& left, const Date& right)
{
	double leftDays = left.m_day + left.m_month * 30.4375 + left.m_year * 365.25;
	double rightDays = right.m_day + right.m_month * 30.4375 + right.m_year * 365.25;
	if (leftDays > rightDays)
	{
		return true;
	}
	return false;
}

bool operator<(const Date& left, const Date& right)
{
	double leftDays = left.m_day + left.m_month * 30.4375 + left.m_year * 365.25;
	double rightDays = right.m_day + right.m_month * 30.4375 + right.m_year * 365.25;
	if (leftDays < rightDays)
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

