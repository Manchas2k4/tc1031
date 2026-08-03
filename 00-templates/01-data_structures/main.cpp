// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file shows the use of the implemented Vector 
//              class.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include "vector.h" // Include the header file.

int main(int argc, char* argv[]) {
    try {
        // **Example 1: Default constructor**
        std::cout << "=== Example 1: Default constructor ===" << std::endl;
        Vector<int> vec1;
        std::cout << "Vector created with default constructor: " << vec1 << std::endl;

        // **Example 2: Constructor with initial size**
        std::cout << "\n=== Example 2: Constructor with initial size ===" << std::endl;
        Vector<int> vec2(5);
        std::cout << "Vector with capacity 5: " << vec2 << std::endl;

        // **Example 3: Constructor with initial size and value**
        std::cout << "\n=== Example 3: Constructor with initial size and value ===" << std::endl;
        Vector<int> vec3(5, 42);
        std::cout << "Vector with capacity 5 and initial value 42: " << vec3 << std::endl;

        // **Example 4: Copy constructor**
        std::cout << "\n=== Example 4: Copy constructor ===" << std::endl;
        Vector<int> vec4 = vec3;
        std::cout << "Vector copied from vec3: " << vec4 << std::endl;

        // **Example 5: Operator []**
        std::cout << "\n=== Example 5: Operator [] ===" << std::endl;
        vec3[2] = 99; // Modify a value in the vector.
        std::cout << "Vector vec3 after modifying index 2: " << vec3 << std::endl;

        // **Example 6: Operator =**
        std::cout << "\n=== Example 6: Operator = ===" << std::endl;
        vec2 = vec3; // Assign vec3 to vec2.
        std::cout << "Vector vec2 after assignment: " << vec2 << std::endl;

        // **Example 7: resize function**
        std::cout << "\n=== Example 7: resize function ===" << std::endl;
        vec3.resize(7); // Resize the vector.
        std::cout << "Vector vec3 after resizing to 7: " << vec3 << std::endl;

        // **Example 8: size function**
        std::cout << "\n=== Example 8: size function ===" << std::endl;
        std::cout << "Size of vec3: " << vec3.size() << std::endl;

        // **Example 9: Vector with strings (std::string)**
        std::cout << "\n=== Example 9: Vector with strings ===" << std::endl;
        Vector<std::string> vecStrings(3, "Hello");
        std::cout << "Vector of strings: " << vecStrings << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}