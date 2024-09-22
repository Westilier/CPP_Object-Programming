#pragma once

#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* string);
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


