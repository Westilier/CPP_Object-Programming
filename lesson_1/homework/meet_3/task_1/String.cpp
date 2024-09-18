#include "String.h"

String::String(const char* string) 
{
	m_size = strlen(string);
	std::cout << m_size;
	char* m_string = new char[m_size];
	size_t i=0;
	while (i < m_size)
	{
		m_string[i] = string[i];
		i++;
	}
}

String::String(size_t size)
{
	m_size = size;
	char* m_string = new char[m_size];
	//m_string[m_size-1] = '\0';
}

String::~String()
{
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
	std::cout << 213;
	if (index < m_size && index >= -static_cast<int>(m_size))
	{
		return m_string[index];
	}
	else
	{
		return 'f';
	}
}

void Print(String string) 
{
	for (size_t i = 0; i < string.GetSize()-1; ++i)
	{
		std::cout << string.GetElement(i);
	}
}
//void String::Print()
//{
//	for (size_t i = 0; i < m_size - 1; ++i)
//	{
//		std::cout << GetElement(i);
//	}
//}


