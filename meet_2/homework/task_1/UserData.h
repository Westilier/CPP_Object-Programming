#pragma once

#include "../../../../libs/String/MyString.h"

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

	void SetName(MyString const& name);
	void SetSurname(MyString const& surname);
	void SetPatronymic(MyString const& patronymic);
	void SetWorkPhoneNumber(MyString const& workPhoneNumber);
	void SetHomePhoneNumber(MyString const& homePhoneNumber);
	void SetAdditionalInformation(MyString const& additionalInformation);

private:
	MyString m_name;
	MyString m_surname;
	MyString m_patronymic;
	MyString m_workPhoneNumber;
	MyString m_homePhoneNumber;
	MyString m_additionalInformation;
};

