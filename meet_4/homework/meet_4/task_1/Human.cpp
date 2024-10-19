#include "Human.h"


Human::Human() : m_FIO{}
{
}

Human::Human(const char* string) : m_FIO{  }
{
	m_FIO = string;
}

Human::Human(const Human& human) : m_FIO{  }
{
	m_FIO = human.m_FIO;
}

Human::~Human()
{
	m_FIO = "";
}

Human& Human::operator=(const Human& other)
{
	if (this != &other)
	{
		m_FIO = other.m_FIO;
	}
	return *this;
}

void Human::Input()
{
	std::getline(std::cin,m_FIO);
}

void Human::Print() const
{
	std::cout << m_FIO << std::endl;
}
