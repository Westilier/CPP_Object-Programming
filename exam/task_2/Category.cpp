#include "Category.h"

Category::Category(std::string name) : m_name{ name }
{
}

void Category::PrintName()
{
	std::cout << m_name << std::endl;
}

void Category::PrintTests()
{
	for (size_t i = 0; i < m_tests.size(); i++)
	{
		std::cout << i + 1<<" - " << m_tests[i].GetName() << std::endl;
	}
}

Test& Category::GetTest(int index)
{
	return m_tests[index];
}

int Category::GetCountTest()
{
	return m_tests.size();
}

std::string Category::GetName()
{
	return m_name;
}

void Category::AddTest(Test test)
{
	m_tests.push_back(test);
}
