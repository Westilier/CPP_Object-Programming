#include "Flat.h"
#include <iostream>

int main()
{
    Flat flat_1(10, 100);
    Flat flat_2(100, 10);
    std::cout << (flat_1 == flat_2 )<< std::endl;
    std::cout << (flat_1 > flat_2) << std::endl;
    flat_1 = flat_2;
    std::cout << (flat_1 == flat_2) << std::endl;
    return 0;
}

