#include "MyString.h"

MyString::MyString() :m_size(81)
{
	MyString::m_count++;

	m_string = new char[m_size];
}

MyString::MyString(const char* myString)
{
	MyString::m_count++;

	m_size = strlen(myString) + 1;
	m_string = new char[m_size];
	if (m_string)
	{
		strcpy_s(m_string, m_size, myString);
	}
}

MyString::MyString(size_t size) :m_size(size)
{
	MyString::m_count++;

	m_string = new char[m_size];
}

MyString::~MyString()
{
	std::cout << 3 << std::endl;
	MyString::m_count--;
	delete[] m_string;
}

void MyString::Resize(size_t size)
{
	m_size = size;
}

size_t MyString::GetSize() const
{
	return m_size;
}

char MyString::GetElement(int index) const
{
	if (index < m_size && m_string != NULL)
	{
		return  m_string[index];
	}
}

char* MyString::GetString() const
{
	return m_string;
}

void MyString::Input()
{
	fgets(m_string, m_size, stdin);
	m_size = strlen(m_string) + 1;
}

void MyString::Print() const
{
	for (size_t i = 0; i < m_size; ++i)
	{
		std::cout << GetElement(i);
	}
}

size_t MyString::Counter()
{
	return m_count;
}

size_t MyString::m_count{ 0 };

bool MyString::Сompare(MyString string)
{
	if (m_size == string.GetSize())
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			if (m_string[i] != string.GetElement(i))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}

}
