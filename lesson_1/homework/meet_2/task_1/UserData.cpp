#include "UserData.h"

void UserData::Input()
{
	std::cout << "������� ��� " << std::endl;
	m_name.Input();
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
}

void UserData::Print()
{
	std::cout << "���: ";
	m_name.Print();
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




