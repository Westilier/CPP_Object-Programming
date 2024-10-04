#include "Human.h"

Human::Human() :m_size{ 81 }, m_FIO{ new char[m_size] }
{
}

Human::Human(const char* string) 
{
	m_size = strlen(string) + 1;
	m_FIO = new char[m_size];
	if (m_FIO)
	{
		strcpy_s(m_FIO, m_size, string);
	}
	m_FIO[m_size-1] = '\n';
}

Human::Human(const Human& human) : m_FIO{ new char[human.m_size] }, m_size{ human.m_size }
{
	for (int i = 0 ; i < m_size; ++i)
	{
		m_FIO[i] = human.m_FIO[i];
	};
}

Human::~Human()
{
	m_FIO = nullptr;
	m_size = 0;
}

Human& Human::operator=(const Human& other)
{
	if (this != &other)
	{
		m_FIO = new char[other.m_size];
		m_size = other.m_size;
		for (int i = 0; i < m_size; ++i)
		{
			m_FIO[i] = other.m_FIO[i];
		};
	}
	return *this;
}

void Human::Input()
{
	fgets(m_FIO, m_size, stdin);
	m_size = strlen(m_FIO) + 1;
}

void Human::Print()
{
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_FIO[i];
	}
}
