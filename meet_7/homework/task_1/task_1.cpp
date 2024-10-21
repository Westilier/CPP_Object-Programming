#include "Overcoat.h"
#include <iostream>

int main()
{
    Overcoat overcoat_1("1",2);
    Overcoat overcoat_2("1", 1);
    std::cout << (overcoat_1 > overcoat_2) << std::endl;
    std::cout << (overcoat_1 == overcoat_2) << std::endl;
    overcoat_1 = overcoat_2;
    std::cout << (overcoat_1 > overcoat_2) << std::endl;
    return 0;
}

