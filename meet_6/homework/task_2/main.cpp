#include "Complex.h"

int main()
{
    Complex complex_1(10, -1);
    Complex complex_2(-5, 2);

    std::cout << complex_1 + complex_2 << std::endl;
    std::cout << complex_1 - complex_2 << std::endl;
    std::cout << complex_1 * complex_2 << std::endl;
    std::cout << complex_1 / complex_2 << std::endl;
    return 0;
}

