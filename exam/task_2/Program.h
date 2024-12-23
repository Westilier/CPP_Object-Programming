#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Test.h"
#include "User.h"
#include "Category.h"


class Program
{
public:
	void LoadStartData();
	void ActivateUser();
	void Work();
	void FinishWork();

	void AdminPossibilities();
	void TesterPossibilities();

	Test ChooseTest();
private:
	std::vector<User> m_users;
	std::vector<Category> m_categories;
	User m_activeUser;
};

