// =================================================================
//
// File: speed.cpp
// Author: Pedro Perez
// Description: This file implements various speed tests on the
//				implemented code.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <chrono>
#include <vector>
#include "header.h"
#include "search.h"

const int SIZE = 1000000000;

using namespace std;
using namespace std::chrono;

/**
 * @brief Main function to test search algorithms and measure execution time.
 * 
 * This program initializes a vector of integers, performs three types of 
 * search algorithms (sequential search, iterative binary search, and 
 * recursive binary search), and measures their execution time in milliseconds.
 * 
 * @param argc Number of command-line arguments (not used in this implementation).
 * @param argv Array of command-line arguments (not used in this implementation).
 * @return int Returns 0 to indicate successful program execution.
 */
int main(int argc, char* argv[]) {
    // Initialize a vector of integers with SIZE elements
    std::vector<int> v(SIZE);
    int result;

    // Variables to measure execution time
    high_resolution_clock::time_point start, end;
    double timeElapsed;

    // Fill the vector with integers from 1 to SIZE
    for (int i = 0; i < SIZE; i++) {
        v[i] = (i + 1);
    }

    // Perform sequential search
    cout << "Starting sequential\n";
    start = high_resolution_clock::now();
    result = sequentialSearch(v, 0);
    end = high_resolution_clock::now();
    timeElapsed = duration<double, std::milli>(end - start).count();
    cout << "result = " << result << "\n";
    cout << "time = " << timeElapsed << " ms\n";

    // Perform iterative binary search
    std::cout << "Starting iterative binary search\n";
    start = high_resolution_clock::now();
    result = iterativeBinarySearch(v, 0);
    end = high_resolution_clock::now();
    timeElapsed = duration<double, std::milli>(end - start).count();
    cout << "result = " << result << "\n";
    cout << "time = " << timeElapsed << " ms\n";

    // Perform recursive binary search
    cout << "Starting recursive binary search\n";
    start = high_resolution_clock::now();
    result = recursiveBinarySearch(v, 0, v.size(), 0);
    end = high_resolution_clock::now();
    timeElapsed =  duration<double, std::milli>(end - start).count();
    cout << "result = " << result << "\n";
    cout << "time = " << timeElapsed << " ms\n";

    return 0;
}
