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

	void SaveToFile();
	//void LoadFromFile(); не рабочая функция

	UserData GetUser(size_t index);

private:
	std::vector<UserData> m_userList;
};

