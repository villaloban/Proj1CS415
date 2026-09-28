#include "task2.h"
#include <fstream>
#include <iostream>

int decrease_by_one(int base, int exponent, int &multiplications)
{
    if (exponent == 0)
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }
    multiplications++;
    return base * decrease_by_one(base, exponent - 1, multiplications);
}

int decrease_by_constant_factor(int base, int exponent, int &multiplications)
{
    if (exponent == 0)
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }
    multiplications++;
    if (exponent % 2 == 0)
    { // even
        int output = decrease_by_constant_factor(base, exponent / 2, multiplications);
        return output * output;
    }
    else
    { // odd
        multiplications++;
        int output = decrease_by_constant_factor(base, (exponent - 1) / 2, multiplications);
        return base * output * output;
    }
}

int divide_and_conquer(int base, int exponent, int &multiplications)
{
    if (exponent == 0)
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }
    multiplications++;
    if (exponent % 2 == 0)
    { // even
        int output = divide_and_conquer(base, exponent / 2, multiplications);
        int output2 = divide_and_conquer(base, exponent / 2, multiplications);
        return output * output2;
    }
    else
    { // odd
        multiplications++;
        int output = divide_and_conquer(base, (exponent - 1) / 2, multiplications);
        int output2 = divide_and_conquer(base, (exponent - 1) / 2, multiplications);
        return base * output * output2;
    }
}

void task2UserMode()
{
    // Implementation for User Mode
    std::cout << "Enter a base: ";
    int base;
    std::cin >> base;
    std::cout << "Enter an exponent: ";
    int exponent;
    std::cin >> exponent;

    int multiplications = 0;
    int result = decrease_by_one(base, exponent, multiplications);
    std::cout << "Decrease by one: " << base << "^" << exponent << " = " << result << std::endl;

    int multiplications2 = 0;
    int result2 = decrease_by_constant_factor(base, exponent, multiplications2);
    std::cout << "Decrease by constant factor: " << base << "^" << exponent << " = " << result2 << std::endl;

    int multiplications3 = 0;
    int result3 = divide_and_conquer(base, exponent, multiplications3);
    std::cout << "Divide and conquer: " << base << "^" << exponent << " = " << result3 << std::endl;
}

void task2PlotMode()
{
    // Implementation for Plot Mode
    std::ofstream outputfile("task2_data.csv");
    outputfile << "n,M_one,M_constant_factor,M_divide_and_conquer" << std::endl;
    int a = 1;
    for (int i = 1; i <= 1000; i++)
    {
        int c1 = 0,
            c2 = 0,
            c3 = 0;

        decrease_by_one(a, i, c1);
        decrease_by_constant_factor(a, i, c2);
        divide_and_conquer(a, i, c3);
        outputfile << i << "," << c1 << "," << c2 << "," << c3 << std::endl;
    }
    outputfile.close();
}