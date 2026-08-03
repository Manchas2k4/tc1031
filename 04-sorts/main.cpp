// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file shows the use of the implemented functions.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <vector>
#include "sorts.h" // Include the header file.

int main(int argc, char* argv[]) {
    // Example vector
    std::vector<int> numbers = {10, 7, 12, 2, 13, 9, 15, 4, 16, 3, 15, 5, 19, 1, 17, 8, 20, 6, 18, 11};

    // Original vector
    std::cout << "Original vector: ";
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **Bubble Sort**
    std::vector<int> bubbleSorted = numbers;
    bubbleSort(bubbleSorted);
    std::cout << "Bubble Sort: ";
    for (const auto &num : bubbleSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **Selection Sort**
    std::vector<int> selectionSorted = numbers;
    selectionSort(selectionSorted);
    std::cout << "Selection Sort: ";
    for (const auto &num : selectionSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **Insertion Sort**
    std::vector<int> insertionSorted = numbers;
    insertionSort(insertionSorted);
    std::cout << "Insertion Sort: ";
    for (const auto &num : insertionSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **Shell Sort**
    std::vector<int> shellSorted = numbers;
    shellSort(shellSorted);
    std::cout << "Shell Sort: ";
    for (const auto &num : shellSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **Merge Sort**
    std::vector<int> mergeSorted = numbers;
    mergeSort(mergeSorted);
    std::cout << "Merge Sort: ";
    for (const auto &num : mergeSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // **QuickSort**
    std::vector<int> quickSorted = numbers;
    quickSort(quickSorted);
    std::cout << "QuickSort: ";
    for (const auto &num : quickSorted) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}