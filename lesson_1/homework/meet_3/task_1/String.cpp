#include "String.h"

String::String() :m_size(81)
{
	String::m_count++;

	m_string = new char[m_size];
}

String::String(const char* string) 
{
	String::m_count++;

	m_size = strlen(string) + 1;
	m_string = new char[m_size];
	if (m_string)
	{
		strcpy_s(m_string, m_size, string);
	}
}

String::String(size_t size) :m_size(size)
{
	String::m_count++;

	m_string = new char[m_size];
}

String::~String()
{
	String::m_count--;
	delete[] m_string;
}

size_t String::GetSize() const
{
	return m_size;
}

void String::Resize(size_t size)
{
	m_size = size;
}

char String::GetElement(int index) const
{
	if (index < m_size && m_string != NULL)
	{
		return  m_string[index];
	}
}

void String::Input()
{
	fgets(m_string, m_size, stdin);
	m_size = strlen(m_string) + 1;
}

void String::Print() const
{
	for (size_t i = 0; i < m_size; ++i)
	{
		std::cout << GetElement(i);
	}
}

size_t String::Counter()
{
	return m_count;
}

size_t String::m_count{ 0 };

