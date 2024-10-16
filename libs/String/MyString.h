#pragma once

#include <iostream>

class MyString
{
public:
	MyString();
	explicit MyString(size_t size);
	MyString(const char* myString);
	MyString(MyString& object);

	MyString(const MyString& object);

	~MyString();

	void Resize(size_t size);

	size_t GetSize() const;
	char GetElement(int index) const;
	char* GetString() const;

	void Input();
	void Print() const;

	static size_t Counter();

	bool Ñompare(MyString string);

	MyString& operator=(const MyString& object);

private:
	size_t m_size;
	char* m_string;
	static size_t m_count;
};


