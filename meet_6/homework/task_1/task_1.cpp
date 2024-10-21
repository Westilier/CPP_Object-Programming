#include "Fraction.h"

int main()
{
    Fraction fraction_1(3, 2);
    Fraction fraction_2(1, 2);

    std::cout << fraction_1 + fraction_2 << std::endl;
    std::cout << fraction_1 - fraction_2 << std::endl;
    std::cout << fraction_1 * fraction_2 << std::endl;
    std::cout << fraction_1 / fraction_2 << std::endl;
    return 0;
}

