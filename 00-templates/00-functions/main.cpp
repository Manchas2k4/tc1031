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
#include <string>
#include "functions.h" // Include the header file.

int main(int argc, char* argv[]) {
    try {
        // **Example 1: Using swap with an array**
        std::cout << "=== Example 1: swap in an array ===" << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        int size = 5;

        std::cout << "Original array: " << toString(arr, size) << std::endl;
        swap(arr, 1, 3); // Swap elements at positions 1 and 3.
        std::cout << "After swap(1, 3): " << toString(arr, size) << std::endl;

        // **Example 2: Using swap with a vector**
        std::cout << "\n=== Example 2: swap in a vector ===" << std::endl;
        std::vector<std::string> vec = {"one", "two", "three", "four"};
        std::cout << "Original vector: " << toString(vec) << std::endl;
        swap(vec, 0, 2); // Swap elements at positions 0 and 2.
        std::cout << "After swap(0, 2): " << toString(vec) << std::endl;

        // **Example 3: Using findFirst with an array**
        std::cout << "\n=== Example 3: findFirst in an array ===" << std::endl;
        int valueToFind = 3;
        int index = findFirst(arr, size, valueToFind);
        std::cout << "First index of " << valueToFind << " in the array: " << index << std::endl;

        // **Example 4: Using findLast with a vector**
        std::cout << "\n=== Example 4: findLast in a vector ===" << std::endl;
        vec = {"one", "two", "three", "two", "four"};
        std::cout << "Vector: " << toString(vec) << std::endl;
        std::string valueToFindStr = "two";
        index = findLast(vec, valueToFindStr);
        std::cout << "Last index of \"" << valueToFindStr << "\" in the vector: " << index << std::endl;

        // **Example 5: Using count with an array**
        std::cout << "\n=== Example 5: count in an array ===" << std::endl;
        int countValue = 2;
        int occurrences = count(arr, size, countValue);
        std::cout << "Number of occurrences of " << countValue << " in the array: " << occurrences << std::endl;

        // **Example 6: Using reverse with a vector**
        std::cout << "\n=== Example 6: reverse in a vector ===" << std::endl;
        std::cout << "Original vector: " << toString(vec) << std::endl;
        reverse(vec); // Reverse the vector.
        std::cout << "After reverse: " << toString(vec) << std::endl;

        // **Example 7: Using toString with an array**
        std::cout << "\n=== Example 7: toString in an array ===" << std::endl;
        double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
        int doubleSize = 4;
        std::cout << "Array of doubles: " << toString(doubleArr, doubleSize) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}