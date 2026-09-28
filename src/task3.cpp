#include "task3.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void selection_sort(int arr[], int size, int &operations)
{
    for (int i = 0; i < size - 1; i++)
    { // size - 1 because dont need to swap last one?
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            operations++; // main operation is the comparison below
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertion_sort(int arr[], int size, int &operations)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            operations++; // main operation is comparison above, the arr[j] > key
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

std::vector<int> loadFile(const std::string &path)
{
    std::vector<int> data;
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return data;
    }

    int value;
    while (file >> value)
    {
        data.push_back(value);
    }

    file.close();
    return data;
}

void task3UserMode()
{
    // Implementation for User Mode
    std::cout << "Enter a value for n: (10-100, step 10): ";
    int n;
    std::cin >> n;
    std::string path = "test data/smallSet/data" + std::to_string(n) + ".txt";
    std::vector<int> data = loadFile(path);

    std::vector<int> copy1 = data;
    int c1 = 0;
    selection_sort(copy1.data(), copy1.size(), c1);
    std::cout << "Selection Sort Comparisons: " << c1 << std::endl;

    std::vector<int> copy2 = data;
    int c2 = 0;
    insertion_sort(copy2.data(), copy2.size(), c2);
    std::cout << "Insertion Sort Comparisons: " << c2 << std::endl;
}

void task3PlotMode()
{
    // Implementation for Plot Mode
    std::ofstream outputFile("task3_best.csv");
    outputFile << "n,Selection Sort,Insertion Sort\n";
    for (int n = 100; n <= 10000; n += 100)
    {
        std::string path = "test data/testSet/data" + std::to_string(n) + "_sorted.txt";
        std::vector<int> data = loadFile(path);

        std::vector<int> copy1 = data;
        int c1 = 0;
        selection_sort(copy1.data(), copy1.size(), c1);

        std::vector<int> copy2 = data;
        int c2 = 0;
        insertion_sort(copy2.data(), copy2.size(), c2);

        outputFile << n << "," << c1 << "," << c2 << "\n";
    }
    outputFile.close();

    outputFile.open("task3_average.csv");
    outputFile << "n,Selection Sort,Insertion Sort\n";
    for (int n = 100; n <= 10000; n += 100)
    {
        std::string path = "test data/testSet/data" + std::to_string(n) + ".txt";
        std::vector<int> data = loadFile(path);

        std::vector<int> copy1 = data;
        int c1 = 0;
        selection_sort(copy1.data(), copy1.size(), c1);

        std::vector<int> copy2 = data;
        int c2 = 0;
        insertion_sort(copy2.data(), copy2.size(), c2);

        outputFile << n << "," << c1 << "," << c2 << "\n";
    }
    outputFile.close();

    outputFile.open("task3_worst.csv");
    outputFile << "n,Selection Sort,Insertion Sort\n";
    for (int n = 100; n <= 10000; n += 100)
    {
        std::string path = "test data/testSet/data" + std::to_string(n) + "_rSorted.txt";
        std::vector<int> data = loadFile(path);

        std::vector<int> copy1 = data;
        int c1 = 0;
        selection_sort(copy1.data(), copy1.size(), c1);

        std::vector<int> copy2 = data;
        int c2 = 0;
        insertion_sort(copy2.data(), copy2.size(), c2);

        outputFile << n << "," << c1 << "," << c2 << "\n";
    }
    outputFile.close();
}
