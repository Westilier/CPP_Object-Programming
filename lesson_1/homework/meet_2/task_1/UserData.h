#pragma once

#include "MyString.h"

class UserData
{
public:
	void Input();
	void Print();

	MyString GetName() const;
	MyString GetSurname() const;
	MyString GetPatronymic() const;
	MyString GetWorkPhoneNumber() const;
	MyString GetHomePhoneNumber() const;
	MyString GetAdditionalInformation() const;

	void SetName(MyString name);
	void SetSurname(MyString surname);
	void SetPatronymic(MyString patronymic);
	void SetWorkPhoneNumber(MyString workPhoneNumber);
	void SetHomePhoneNumber(MyString homePhoneNumber);
	void SetAdditionalInformation(MyString additionalInformation);

	operator==
private:
	MyString m_name;
	MyString m_surname;
	MyString m_patronymic;
	MyString m_workPhoneNumber;
	MyString m_homePhoneNumber;
	MyString m_additionalInformation;
};

