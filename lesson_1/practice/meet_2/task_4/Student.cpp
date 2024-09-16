#include "Student.h"

Student::Student(std::string name,
	std::string surname,
	std::string patronymic,
	std::string dateOfBirth,
	std::string phoneNumber,
	std::string city,
	std::string country,
	std::string educationalInstitution,
	std::string cityOfEducationalInstitution,
	std::string countryOfEducationalInstitution,
	std::string numberOfGroup)
	:m_name(name),
	m_surname(surname),
	m_patronymic(patronymic),
	m_dateOfBirth(dateOfBirth),
	m_phoneNumber(phoneNumber),
	m_city(city),
	m_country(country),
	m_educationalInstitution(educationalInstitution),
	m_cityOfEducationalInstitution(cityOfEducationalInstitution),
	m_countryOfEducationalInstitution(countryOfEducationalInstitution),
	m_numberOfGroup(numberOfGroup)
{
}

void Student::PrintData()
{
	std::cout << "���: " << m_name << std::endl
		<< "�������:" << m_surname << std::endl
		<< "��������: " << m_patronymic << std::endl
		<< "���� ��������: " << m_dateOfBirth << std::endl
		<< "����� ��������: " << m_phoneNumber << std::endl
		<< "�����: " << m_city << std::endl
		<< "������: " << m_country << std::endl
		<< "�������� ���������: " << m_educationalInstitution << std::endl
		<< "�����, ��� ����������� �������� ���������: " << m_cityOfEducationalInstitution << std::endl
		<< "������, ��� ����������� �������� ���������: " << m_countryOfEducationalInstitution << std::endl
		<< "����� ������: " << m_numberOfGroup << std::endl;
}

void Student::InputData()
{
	std::cout << "������� ��� ";
	getline(std::cin, m_name);
	std::cout << "������� ������� ";
	getline(std::cin, m_surname);
	std::cout << "������� �������� ";
	getline(std::cin, m_patronymic);
	std::cout << "������� ���� �������� ";
	getline(std::cin, m_dateOfBirth);
	std::cout << "������� ����� �������� ";
	getline(std::cin, m_phoneNumber);
	std::cout << "������� ����� ";
	getline(std::cin, m_city);
	std::cout << "������� ������ ";
	getline(std::cin, m_country);
	std::cout << "������� �������� �������� ��������� ";
	getline(std::cin, m_educationalInstitution);
	std::cout << "������� �����, ��� ����������� �������� ��������� ";
	getline(std::cin, m_cityOfEducationalInstitution);
	std::cout << "������� ������, ��� ����������� �������� ��������� ";
	getline(std::cin, m_countryOfEducationalInstitution);
	std::cout << "������� ����� ������ ";
	getline(std::cin, m_numberOfGroup);
}

void Student::SetName(std::string name)
{
	m_name = name;
}

void Student::SetSurname(std::string surname)
{
	m_surname = surname;
}

void Student::SetPatronymic(std::string patronymic)
{
	m_patronymic = patronymic;
}

void Student::SetDateOfBirth(std::string dateOfBirth)
{
	m_dateOfBirth = dateOfBirth;
}

void Student::SetPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void Student::SetCity(std::string city)
{
	m_city = city;
}

void Student::SetCountry(std::string country)
{
	m_country = country;
}

void Student::SetEducationalInstitution(std::string educationalInstitution)
{
	m_educationalInstitution = educationalInstitution;
}

void Student::SetCityOfEducationalInstitution(std::string cityOfEducationalInstitution)
{
	m_cityOfEducationalInstitution = cityOfEducationalInstitution;
}

void Student::SetCountryOfEducationalInstitution(std::string countryOfEducationalInstitution)
{
	m_countryOfEducationalInstitution = countryOfEducationalInstitution;
}

void Student::SetnumberOfGroup(std::string numberOfGroup)
{
	m_numberOfGroup = numberOfGroup;
}

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
