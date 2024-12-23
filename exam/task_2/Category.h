#pragma once
#include <vector>
#include "Test.h"

class Category
{
public:
	Category(std::string name);

	void PrintName();
	void PrintTests();	

	void AddTest(Test test);

	Test& GetTest(int index);
	int GetCountTest();
	std::string GetName();
private:
	std::string m_name;
	std::vector<Test> m_tests;
};

