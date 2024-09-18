#pragma once

#include <iostream>

class String
{
public:
	String(const char * string);
	explicit String(size_t size = 10);
	~String();

	size_t GetSize() const;
	void Resize(size_t size);
	char GetElement(int index) const;
	void Print() const;
	friend void Print(String String);
private:
	size_t m_size;
	char*  m_string;


};

