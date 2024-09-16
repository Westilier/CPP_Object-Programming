#pragma once
#include<iostream>
#include<string>

class Student
{
public:
	void PrintData();
	void InputData();

	void SetName(std::string name);
	void SetSurname(std::string surname);
	void SetPatronymic(std::string patronymic);
	void SetDateOfBirth(std::string dateOfBirth);
	void SetPhoneNumber(std::string phoneNumber);
	void SetCity(std::string city);
	void SetCountry(std::string country);
	void SetEducationalInstitution(std::string educationalInstitution);
	void SetCityOfEducationalInstitution(std::string cityOfEducationalInstitution);
	void SetCountryOfEducationalInstitution(std::string countryOfEducationalInstitution);
	void SetnumberOfGroup(std::string numberOfGroup);

	std::string GetName();
	std::string GetSurname();
	std::string GetPatronymic();
	std::string GetDateOfBirth();
	std::string GetPhoneNumber();
	std::string GetCity();
	std::string GetCountry();
	std::string GetEducationalInstitution();
	std::string GetCityOfEducationalInstitution();
	std::string GetCountryOfEducationalInstitution();
	std::string GetnumberOfGroup();

private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	std::string m_dateOfBirth;
	std::string m_phoneNumber;
	std::string m_city;
	std::string m_country;
	std::string m_educationalInstitution;
	std::string m_cityOfEducationalInstitution;
	std::string m_countryOfEducationalInstitution;
	std::string m_numberOfGroup;
};

