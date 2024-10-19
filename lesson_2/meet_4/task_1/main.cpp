#include"House.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Human man("man");
	Apartment apartment;
	House house;
	apartment.AddHuman(man);
	apartment.Print();
	house.AddApartment(apartment);
	house.Print();
	return 0;
}