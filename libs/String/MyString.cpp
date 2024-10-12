#include "MyString.h"

size_t MyString::m_count{ 0 };

MyString::MyString() :m_size(81)
{
	MyString::m_count++;

	m_string = new char[m_size];
}

MyString::MyString(size_t size) :m_size(size)
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

MyString::MyString(std::string& object)
	:m_size(object.size()), m_string(new char[m_size+1])
{
	strcpy(m_string, object.c_str());
}

MyString::MyString(const MyString& object)
	: m_string{ new char[object.m_size] }, m_size{ object.m_size }
{
	m_string = object.m_string;
}

MyString::~MyString()
{
	if (m_string != nullptr)
	{
		MyString::m_count--;
		delete[] m_string;
		std::cout << "del";
	}
	std::cout << "no del";
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

MyString& MyString::operator=(const MyString& object)
{
	if (this != &object)
	{
		delete[] m_string;
		m_string = new char[object.m_size];
		m_string = object.m_string;
		m_size = object.m_size;
	}
	return *this;
}
