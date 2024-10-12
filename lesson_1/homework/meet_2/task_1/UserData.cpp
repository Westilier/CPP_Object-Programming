#include "UserData.h"

void UserData::Input()
{
	std::cin.ignore(20, '\n');
	std::cout << "Введите имя " << std::endl;
	//m_name.Input();
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
	std::cout << std::endl;
}

void UserData::Print()
{
	std::cout << "Имя: ";
	//m_name.Print();
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

inline MyString UserData::GetName() const
{
	return m_name;
}

inline MyString UserData::GetSurname() const
{
	return m_surname;
}

inline MyString UserData::GetPatronymic() const
{
	return m_patronymic;
}

inline MyString UserData::GetWorkPhoneNumber() const
{
	return m_workPhoneNumber;
}

inline MyString UserData::GetHomePhoneNumber() const
{
	return m_homePhoneNumber;
}

inline MyString UserData::GetAdditionalInformation() const
{
	return m_additionalInformation;
}

void UserData::SetName(MyString const& name)
{
	m_name = name;
}

void UserData::SetSurname(MyString const& surname)
{
	m_surname = surname;
}

void UserData::SetPatronymic(MyString const& patronymic)
{
	m_patronymic = patronymic;
}

void UserData::SetWorkPhoneNumber(MyString const& workPhoneNumber)
{
	m_workPhoneNumber = workPhoneNumber;
}

void UserData::SetHomePhoneNumber(MyString const& homePhoneNumber)
{
	m_homePhoneNumber = homePhoneNumber;
}

void UserData::SetAdditionalInformation(MyString const& additionalInformation)
{
	m_additionalInformation = additionalInformation;
}
