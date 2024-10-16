#pragma once
#include<vector>

#include"Human.h"


class Apartment
{
public:
	Apartment();
	Apartment(const Apartment& apartment);
	~Apartment();

	Apartment& operator=(const Apartment& other);

	void AddHuman(Human const& human);
	void Print();
	void Input(Human human, size_t number);
private:
	std::vector<Human> m_humans;
	size_t m_number;
};

