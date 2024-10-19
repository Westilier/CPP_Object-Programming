#pragma once
#include <string>
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
	void Print() const;
private :
	std::string m_FIO;
};

