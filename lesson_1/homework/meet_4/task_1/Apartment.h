#pragma once
#include"Human.h"

class Apartment
{
public:
	Apartment();
	Apartment(size_t size);
	Apartment(Apartment& apartment);
	~Apartment();

	Apartment& operator=(const Apartment& other);

	void AddHuman(Human human);
	void Print();
	void Input(Human human, size_t number);
private:
	Human* m_humans;
	size_t m_size;
	size_t m_number;
};

