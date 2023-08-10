// =================================================================
//
// File: template_functions.cpp
// Author: Pedro Perez
// Description: This file you will find an example of the use of 
//              template functions in C/C++.
//
// Copyright (c) 2023 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>
#include <iomanip>

using namespace std;

// =================================================================
// Returns the position of value within the array arr. If the element 
// is not found, return -1.
//
// @param arr, an array of elements of type T.
// @param size, the number of elements in the array.
// @param value, the item to find.
// @return the position of value within the array arr. If the element 
//         is not found, return -1.
// =================================================================
template <class T>
int indexOf(T *arr, int size, T value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    int a1[5] = {0, 1, 2, 3, 4};
    float a2[5] = {0.1, 1.1, 2.1, 3.1, 4.1};

    /* Using indexof on two arrays of different types. */
    cout << "Looking for the value 5 in array arr1, is it? " << indexOf(a1, 5, 5) << "\n";
    cout << "Looking for the value 0.5 in array arr2, is it? " << indexOf(a2, 5, 0.5f) << "\n";

    ss
    return 0;
}