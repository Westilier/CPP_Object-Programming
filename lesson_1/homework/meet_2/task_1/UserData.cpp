#include "UserData.h"

void UserData::Input()
{
	std::cin.ignore(20, '\n');
	std::cout << "������� ��� " << std::endl;
	//m_name.Input();
	std::cout << "������� ������� " << std::endl;
	m_surname.Input();
	std::cout << "������� �������� " << std::endl;
	m_patronymic.Input();
	std::cout << "������� ������� ����� ������� " << std::endl;
	m_workPhoneNumber.Input();
	std::cout << "������� �������� ����� �������� " << std::endl;
	m_homePhoneNumber.Input();
	std::cout << "������� �������������� ����������" << std::endl;
	m_additionalInformation.Input();
	std::cout << std::endl;
}

void UserData::Print()
{
	std::cout << "���: ";
	//m_name.Print();
	std::cout << "�������: ";
	m_surname.Print();
	std::cout << "��������: ";
	m_patronymic.Print();
	std::cout << "������� ����� �������: ";
	m_workPhoneNumber.Print();
	std::cout << "�������� ����� ��������: ";
	m_homePhoneNumber.Print();
	std::cout << "�������������� ����������: ";
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
