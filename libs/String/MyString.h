#pragma once

#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* string);
	MyString(const MyString& object)
		: m_string{ new char[object.m_size] }, m_size{ object.m_size }
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			m_string[i] = object.m_string[i];
		};
	}
	explicit MyString(size_t size);

	~MyString();

	void Resize(size_t size);

	size_t GetSize() const;
	char GetElement(int index) const;
	char* GetString() const;

	void Input();
	void Print() const;

	static size_t Counter();

	bool Ñompare(MyString string);

private:
	size_t m_size;
	char* m_string{ nullptr };
	static size_t m_count;
};


