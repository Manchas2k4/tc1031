// =================================================================
//
// File: functions.h
// Author: Pedro Perez
// Description: This file contains examples of the use of templates 
//              in generic functions.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <stdexcept>

/**
 * @brief Swaps two elements in an array.
 * 
 * @tparam T Type of the elements in the array.
 * @param A Pointer to the array. Must not be null.
 * @param i Index of the first element to swap. Must be within bounds.
 * @param j Index of the second element to swap. Must be within bounds.
 * @throw std::out_of_range If indices are out of bounds.
 */
template <class T>
void swap(T *A, int i, int j) {
    if (!A) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (i < 0 || j < 0) {
        throw std::out_of_range("Indices must be non-negative.");
    }
    T aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}

/**
 * @brief Swaps two elements in a vector.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 * @param i Index of the first element to swap. Must be within bounds.
 * @param j Index of the second element to swap. Must be within bounds.
 * @throw std::out_of_range If indices are out of bounds.
 */
template <class T>
void swap(std::vector<T> &v, int i, int j) {
    if (i < 0 || j < 0 || i >= v.size() || j >= v.size()) {
        throw std::out_of_range("Indices must be within bounds.");
    }
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/**
 * @brief Finds the first occurrence of a value in an array.
 * 
 * @tparam T Type of the elements in the array.
 * @param arr Pointer to the array. Must not be null.
 * @param size Size of the array. Must be non-negative.
 * @param value Value to find.
 * @return Index of the first occurrence of the value, or -1 if not found.
 * @throw std::invalid_argument If the array pointer is null.
 */
template <class T>
int findFirst(const T *arr, int size, T value) {
    if (!arr) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (size < 0) {
        throw std::invalid_argument("Array size cannot be negative.");
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the first occurrence of a value in a vector.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 * @param value Value to find.
 * @return Index of the first occurrence of the value, or -1 if not found.
 */
template <class T>
int findFirst(const std::vector<T> &v, T value) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the last occurrence of a value in an array.
 * 
 * @tparam T Type of the elements in the array.
 * @param arr Pointer to the array. Must not be null.
 * @param size Size of the array. Must be non-negative.
 * @param value Value to find.
 * @return Index of the last occurrence of the value, or -1 if not found.
 * @throw std::invalid_argument If the array pointer is null.
 */
template <class T>
int findLast(const T *arr, int size, T value) {
    if (!arr) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (size < 0) {
        throw std::invalid_argument("Array size cannot be negative.");
    }
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the last occurrence of a value in a vector.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 * @param value Value to find.
 * @return Index of the last occurrence of the value, or -1 if not found.
 */
template <class T>
int findLast(const std::vector<T> &v, T value) {
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Counts the occurrences of a value in an array.
 * 
 * @tparam T Type of the elements in the array.
 * @param arr Pointer to the array. Must not be null.
 * @param size Size of the array. Must be non-negative.
 * @param value Value to count.
 * @return Number of occurrences of the value.
 * @throw std::invalid_argument If the array pointer is null.
 */
template <class T>
int count(const T *arr, int size, T value) {
    if (!arr) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (size < 0) {
        throw std::invalid_argument("Array size cannot be negative.");
    }
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            counter++;
        }
    }
    return counter;
}

/**
 * @brief Counts the occurrences of a value in a vector.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 * @param value Value to count.
 * @return Number of occurrences of the value.
 */
template <class T>
int count(const std::vector<T> &v, T value) {
    int counter = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == value) {
            counter++;
        }
    }
    return counter;
}

/**
 * @brief Reverses the elements of an array.
 * 
 * @tparam T Type of the elements in the array.
 * @param arr Pointer to the array. Must not be null.
 * @param size Size of the array. Must be non-negative.
 * @throw std::invalid_argument If the array pointer is null.
 */
template <class T>
void reverse(T *arr, int size) {
    if (!arr) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (size < 0) {
        throw std::invalid_argument("Array size cannot be negative.");
    }
    int i = 0;
    int j = size - 1;

    while (i < j) {
        swap(arr, i, j);
        i++;
        j--;
    }
}

/**
 * @brief Reverses the elements of a vector.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 */
template <class T>
void reverse(std::vector<T> &v) {
    int i = 0;
    int j = v.size() - 1;

    while (i < j) {
        swap(v, i, j);
        i++;
        j--;
    }
}

/**
 * @brief Converts the elements of an array to a string representation.
 * 
 * @tparam T Type of the elements in the array.
 * @param A Pointer to the array. Must not be null.
 * @param size Size of the array. Must be non-negative.
 * @return String representation of the array.
 * @throw std::invalid_argument If the array pointer is null.
 */
template <class T>
std::string toString(const T *A, int size) {
    if (!A) {
        throw std::invalid_argument("Array pointer cannot be null.");
    }
    if (size < 0) {
        throw std::invalid_argument("Array size cannot be negative.");
    }
    std::ostringstream aux;

    aux << "[";
    for (int i = 0; i < size; i++) {
        aux << A[i];
        if (i < size - 1) {
            aux << ", ";
        }
    }
    aux << "]";
    return aux.str();
}

/**
 * @brief Converts the elements of a vector to a string representation.
 * 
 * @tparam T Type of the elements in the vector.
 * @param v Reference to the vector.
 * @return String representation of the vector.
 */
template <class T>
std::string toString(const std::vector<T> &v) {
    std::ostringstream aux;

    aux << "[";
    for (int i = 0; i < v.size(); i++) {
        aux << v[i];
        if (i < v.size() - 1) {
            aux << ", ";
        }
    }
    aux << "]";
    return aux.str();
}

#endif