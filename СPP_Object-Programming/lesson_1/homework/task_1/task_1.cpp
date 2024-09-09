#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction fraction_1(3, 2);
    Fraction fraction_2(1, 2);

    fraction_1.Divide(fraction_2);
    fraction_1.Reduce();
    std::cout << fraction_1.GetNumerator() << std::endl
            << fraction_1.GetDenominator() << std::endl
            << std::endl;

    fraction_1.Multiply(fraction_2);
    fraction_1.Reduce();
    std::cout << fraction_1.GetNumerator() << std::endl
            << fraction_1.GetDenominator() << std::endl
            << std::endl;

    fraction_1.Subtract(fraction_2);
    fraction_1.Reduce();
    std::cout << fraction_1.GetNumerator() << std::endl
            << fraction_1.GetDenominator() << std::endl
            << std::endl;

    fraction_1.Add(fraction_2);
    fraction_1.Reduce();
    std::cout << fraction_1.GetNumerator() << std::endl
            << fraction_1.GetDenominator() << std::endl
            << std::endl;
    return 0;
}

