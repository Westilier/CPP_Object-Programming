#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Test.h"

class User
{
public:
	User();
	User(const User& object);

	void Registration(std::vector<User>& user);
	bool Enter(std::vector<User>& users);
	void PassTest(Test test);
	bool DeleteUser(std::vector<User>& users);
	bool IsAdmin();
	void FindUser(std::string login, std::vector<User>& users);

	void ChangeLogin(std::string newLogin, std::vector<User>& users);
	void ChangePassword(std::string newPassword);
	void ChangeFIO(std::string login, std::vector<User>& users);
	void ChangeAddress(std::string login, std::vector<User>& users);
	void ChangeNumber(std::string login, std::vector<User>& users);

	std::string GetFIO();
	std::vector<Test> GetPassedTests();

	User& operator=(const User& object);

	friend std::ostream& operator<<(std::ostream& stream, const User& user);
	friend std::istream& operator>>(std::istream& stream, User& user);
private:
	std::string EncryptDecrypt(std::string& toEncrypt);

	std::string m_login;
	std::string m_password;
	std::string m_FIO;
	std::string m_address;
	std::string m_phone;
	std::vector<Test> m_passedTests;
	bool m_isAdmin; 
};

