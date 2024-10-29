#include"Date.h"
int main()
{
	Date date_1;
	Date date_2(1, -1, 11);
	std::cout << date_1 << std::endl << date_2 << std::endl;

	std::cout << date_1 + 20 << std::endl;
	std::cout << date_1 - 40 << std::endl;

	std::cout << (date_1 > date_2) << std::endl;
	std::cout << (date_1 < date_2) << std::endl;

	date_1 = date_2;
	std::cout << (date_1 == date_2) << std::endl;
	return 0;
}