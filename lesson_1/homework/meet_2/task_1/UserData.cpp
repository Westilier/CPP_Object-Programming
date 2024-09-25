#include "UserData.h"

void UserData::Input()
{
	std::cout << "Введите имя " << std::endl;
	m_name.Input();
	std::cout << "Введите фамилию " << std::endl;
	m_surname.Input();
	std::cout << "Введите отчество " << std::endl;
	m_patronymic.Input();
	std::cout << "Введите рабочий номер телефон " << std::endl;
	m_workPhoneNumber.Input();
	std::cout << "Введите домашний номер телефона " << std::endl;
	m_homePhoneNumber.Input();
	std::cout << "Введите дополнительную информацию" << std::endl;
	m_additionalInformation.Input();
}

void UserData::Print()
{
	std::cout << "Имя: ";
	m_name.Print();
	std::cout << "Фамилию: ";
	m_surname.Print();
	std::cout << "Отчество: ";
	m_patronymic.Print();
	std::cout << "Рабочий номер телефон: ";
	m_workPhoneNumber.Print();
	std::cout << "Домашний номер телефона: ";
	m_homePhoneNumber.Print();
	std::cout << "Дополнительную информацию: ";
	m_additionalInformation.Print();
}

MyString UserData::GetName() const
{
	return m_name;
}

MyString UserData::GetSurname() const
{
	return m_surname;
}

MyString UserData::GetPatronymic() const
{
	return m_patronymic;
}

MyString UserData::GetWorkPhoneNumber() const
{
	return m_workPhoneNumber;
}

MyString UserData::GetHomePhoneNumber() const
{
	return m_homePhoneNumber;
}

MyString UserData::GetAdditionalInformation() const
{
	return m_additionalInformation;
}

void UserData::SetName(MyString name)
{
	m_name = name;
}

void UserData::SetSurname(MyString surname)
{
	m_surname = surname;
}

void UserData::SetPatronymic(MyString patronymic)
{
	m_patronymic = patronymic;
}

void UserData::SetWorkPhoneNumber(MyString workPhoneNumber)
{
	m_workPhoneNumber = workPhoneNumber;
}

void UserData::SetHomePhoneNumber(MyString homePhoneNumber)
{
	m_homePhoneNumber = homePhoneNumber;
}

void UserData::SetAdditionalInformation(MyString additionalInformation)
{
	m_additionalInformation = additionalInformation;
}




