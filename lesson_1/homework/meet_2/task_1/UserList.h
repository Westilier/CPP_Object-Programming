#pragma once

#include "UserData.h"

#include <fstream>
#include <vector>
#include <string>

class UserList
{
public:
	~UserList();

	void AddUser(UserData user);
	void DeleteUser(MyString Surname);

	void PrintAllUsers();

	int SearchByName(MyString name);
	int SearchBySurname(MyString surname);
	int SearchByPatronymic(MyString patronymic);

	void SaveToFile(MyString fileName);
	void LoadFromFile(MyString fileName);

	UserData GetUser(size_t index);

private:
	std::vector<UserData> m_userList;
};

