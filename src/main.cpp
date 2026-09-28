#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <iostream>

int main()
{
    std::cout << "1) User Mode" << '\n';
    std::cout << "2) Scatter Plot Mode" << '\n';
    std::cout << "0) Exit" << '\n';
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Which Task? (1/2/3)" << '\n';
        int taskChoice;
        std::cin >> taskChoice;
        if (taskChoice == 1)
        {
            task1UserMode();
        }
        else if (taskChoice == 2)
        {
            task2UserMode();
        }
        else if (taskChoice == 3)
        {
            task3UserMode();
        }
    }
    if (choice == 2)
    {
        // Handle scatter plot mode
        task1PlotMode();
        task2PlotMode();
        task3PlotMode();
        std::cout << "CSV files successfully written." << '\n';
    }
    return 0;
}