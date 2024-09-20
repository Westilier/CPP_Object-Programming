#pragma once

#include <iostream>

class String
{
public:
	String();
	explicit String(const char * string);
	explicit String(size_t size);

	~String();

	size_t GetSize() const;
	void Resize(size_t size);
	char GetElement(int index) const;

	void Input();
	void Print() const;

	static size_t Counter();

private:
	size_t m_size;
	char* m_string{nullptr};
	static size_t m_count;
};


