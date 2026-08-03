// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file shows the use of various search algorithms 
//              (sequential search, iterative binary search, and 
//              recursive binary search) using example vectors.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include "search.h" // Include the header file.

/**
 * @brief Main function that demonstrates the usage of search algorithms.
 * 
 * This program tests various search algorithms (sequential search, iterative binary search, 
 * and recursive binary search) using example vectors. It also handles edge cases like searching 
 * in an empty vector or searching for a non-existent value.
 * 
 * @param argc Number of command-line arguments (not used in this implementation).
 * @param argv Array of command-line arguments (not used in this implementation).
 * @return int Returns 0 to indicate successful program execution.
 */
int main(int argc, char* argv[]) {
    // Example vector
    std::vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // **Example 1: Sequential Search**
    std::cout << "=== Example 1: Sequential Search ===" << std::endl;
    int index = sequentialSearch(numbers, 7);
    if (index != -1) {
        std::cout << "Found 7 at index: " << index << std::endl;
    } else {
        std::cout << "7 not found in the vector." << std::endl;
    }

    // **Example 2: Iterative Binary Search**
    std::cout << "\n=== Example 2: Iterative Binary Search ===" << std::endl;
    index = iterativeBinarySearch(numbers, 7);
    if (index != -1) {
        std::cout << "Found 7 at index: " << index << std::endl;
    } else {
        std::cout << "7 not found in the vector." << std::endl;
    }

    // **Example 3: Recursive Binary Search**
    std::cout << "\n=== Example 3: Recursive Binary Search ===" << std::endl;
    index = recursiveBinarySearch(numbers, 0, numbers.size() - 1, 7);
    if (index != -1) {
        std::cout << "Found 7 at index: " << index << std::endl;
    } else {
        std::cout << "7 not found in the vector." << std::endl;
    }

    return 0;
}