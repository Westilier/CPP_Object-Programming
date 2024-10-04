#pragma once
#include <string.h>
#include <iostream>

class Human
{
public:
	Human();
	Human(const char* string);
	Human(const Human& human);
	~Human();

	Human& operator=(const Human& other);

	void Input();
	void Print();
private :
	char* m_FIO {nullptr};
	size_t m_size;
};

