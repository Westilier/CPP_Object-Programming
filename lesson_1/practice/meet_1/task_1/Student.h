#pragma once
#include<iostream>

class Student
{
public:
	void PrintData();
	void InputData();

	void SetName();
	void SetSurname();
	void SetPatronymic();
	void SetDateOfBirth();
	void SetPhoneNumber();
	void SetCity();
	void SetCountry();
	void SetEducationalInstitution();
	void SetCityOfEducationalInstitution();
	void SetCountryOfEducationalInstitution();
	void SetnumberOfGroup();

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

