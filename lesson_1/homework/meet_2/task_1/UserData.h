#pragma once

#include "MyString.h"

class UserData
{
public:

	void Input();
	void Print();

	inline MyString GetName() const;
	inline MyString GetSurname() const;
	inline MyString GetPatronymic() const;
	inline MyString GetWorkPhoneNumber() const;
	inline MyString GetHomePhoneNumber() const;
	inline MyString GetAdditionalInformation() const;

	void SetName(MyString name);
	void SetSurname(MyString surname);
	void SetPatronymic(MyString patronymic);
	void SetWorkPhoneNumber(MyString workPhoneNumber);
	void SetHomePhoneNumber(MyString homePhoneNumber);
	void SetAdditionalInformation(MyString additionalInformation);

private:
	MyString m_name;
	MyString m_surname;
	MyString m_patronymic;
	MyString m_workPhoneNumber;
	MyString m_homePhoneNumber;
	MyString m_additionalInformation;
};

