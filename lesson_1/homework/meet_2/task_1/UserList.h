#pragma once

#include "UserData.h"

#include <fstream>
#include <vector>
#include <string>


class UserList
{
public:

	void AddUser(UserData const& user);
	void DeleteUser(MyString& Surname);

	void PrintAllUsers();

	int SearchByName(MyString& name);
	int SearchBySurname(MyString& surname);
	int SearchByPatronymic(MyString& patronymic);

	void SaveToFile(MyString fileName);
	void LoadFromFile(MyString fileName);

	UserData GetUser(size_t index);
	std::vector<UserData> Vector()
	{
		return m_userList;
	}
private:
	std::vector<UserData> m_userList;
};

