#include "task1.h"
#include <fstream>
#include <iostream>
#include <filesystem>

int fib(int k, int &counter)
{
    if (k <= 1)
    {
        return k;
    }
    int compu1 = fib(k - 1, counter);
    int compu2 = fib(k - 2, counter);
    counter++;
    return compu1 + compu2;
}

int gcd(int m, int n, int &counter)
{
    if (n == 0)
    {
        return m;
    }
    counter++;
    return gcd(n, m % n, counter);
}

void task1UserMode()
{
    // Implementation for user mode
    std::cout << "Enter a value for k: ";
    int k;
    std::cin >> k;
    int fibCount = 0;
    int fibResults = fib(k, fibCount);
    std::cout << "fib(" << k << ") = " << fibResults << "\n";

    int gcdCount = 0;
    int m = fib(k + 1, gcdCount);
    int g = gcd(m, fibResults, gcdCount);
    std::cout << "GCD(" << m << ", " << fibResults << ") = " << g << "\n";
}

void task1PlotMode()
{
    // Implementation for plot mode
    std::filesystem::create_directories("results/task1_results");
    std::ofstream outputFile("results/task1_results/task1_Fibonacci_results.csv");

    outputFile << "k,A\n";
    for (int k = 1; k <= 35; k++)
    {
        int counter = 0;
        outputFile << k << "," << counter << "\n";
    }
    outputFile.close();

    outputFile.open("results/task1_results/task1_GCD_results.csv");
    outputFile << "n,D\n";
    for (int k = 1; k <= 35; k++)
    {
        int counter = 0;
        int n = fib(k, counter);
        int m = fib(k + 1, counter);
        counter = 0;
        gcd(m, n, counter);
        outputFile << n << "," << counter << "\n";
    }
    outputFile.close();
}