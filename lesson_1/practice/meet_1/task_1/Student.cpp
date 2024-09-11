#include "Student.h"

void Student::PrintData();
void Student::InputData();

void Student::SetName();
void Student::SetSurname();
void Student::SetPatronymic();
void Student::SetDateOfBirth();
void Student::SetPhoneNumber();
void Student::SetCity();
void Student::SetCountry();
void Student::SetEducationalInstitution();
void Student::SetCityOfEducationalInstitution();
void Student::SetCountryOfEducationalInstitution();
void Student::SetnumberOfGroup();

std::string Student::GetName()
{
	return m_name;
}

std::string Student::GetSurname()
{
	return m_surname;
}

std::string Student::GetPatronymic()
{
	return m_patronymic;
}

std::string Student::GetDateOfBirth()
{
	return m_dateOfBirth;
}

std::string Student::GetPhoneNumber()
{
	return m_phoneNumber;
}

std::string Student::GetCity()
{
	return m_city;
}

std::string Student::GetCountry()
{
	return m_country;
}

std::string Student::GetEducationalInstitution()
{
	return m_educationalInstitution;
}

std::string Student::GetCityOfEducationalInstitution()
{
	return m_cityOfEducationalInstitution;
}

std::string Student::GetCountryOfEducationalInstitution()
{
	return m_countryOfEducationalInstitution;
}

std::string Student::GetnumberOfGroup()
{
	return m_numberOfGroup;
}