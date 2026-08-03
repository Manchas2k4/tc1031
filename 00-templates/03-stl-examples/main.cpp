// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file shows the use of the various stl functions.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <vector>
#include <algorithm> // For find, count, reverse, replace
#include <iterator>  // For std::distance

int main() {
    // Create a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 3, 2, 1};

    // **Using std::find**
    int valueToFind = 3;
    auto it = std::find(vec.begin(), vec.end(), valueToFind);
    if (it != vec.end()) {
        std::cout << "The value " << valueToFind << " was found at index: "
                  << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "The value " << valueToFind << " was not found in the vector." << std::endl;
    }

    // **Using std::count**
    int valueToCount = 2;
    int occurrences = std::count(vec.begin(), vec.end(), valueToCount);
    std::cout << "The value " << valueToCount << " appears " << occurrences << " times in the vector." << std::endl;

    // **Using std::reverse**
    std::cout << "Original vector: ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::reverse(vec.begin(), vec.end());
    std::cout << "Vector after reversing: ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // **Using std::replace**
    int oldValue = 2;
    int newValue = 5;
    std::replace(vec.begin(), vec.end(), oldValue, newValue);
    std::cout << "Vector after replacing " << oldValue << " with " << newValue << ": ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}