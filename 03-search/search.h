// =================================================================
//
// File: search.h
// Author: Pedro Perez
// Description: This file contains the implementations of the
//				sequential and binary search algorithms.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include <vector>
#include <stdexcept> // Para manejo de excepciones

/**
 * @brief Performs a sequential search on a vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector to search in.
 * @param key The key to search for.
 * @return The index of the key in the vector, or -1 if the key is not found.
 * @throw std::invalid_argument If the vector is empty.
 */
template <class T>
int sequentialSearch(const std::vector<T> &v, T key) {
    if (v.empty()) {
        throw std::invalid_argument("sequentialSearch: The vector is empty.");
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Performs an iterative binary search on a sorted vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The sorted vector to search in.
 * @param key The key to search for.
 * @return The index of the key in the vector, or -1 if the key is not found.
 * @throw std::invalid_argument If the vector is empty.
 */
template <class T>
int iterativeBinarySearch(const std::vector<T> &v, T key) {
    if (v.empty()) {
        throw std::invalid_argument("iterativeBinarySearch: The vector is empty.");
    }

    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + ((high - low) / 2); // Prevents overflow compared to (high + low) / 2
        if (key == v[mid]) {
            return mid;
        } else if (key < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

/**
 * @brief Performs a recursive binary search on a sorted vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The sorted vector to search in.
 * @param low The lower index of the range to search in.
 * @param high The upper index of the range to search in.
 * @param key The key to search for.
 * @return The index of the key in the vector, or -1 if the key is not found.
 * @throw std::invalid_argument If the vector is empty.
 */
template <class T>
int recursiveBinarySearch(const std::vector<T> &v, int low, int high, T key) {
    if (v.empty()) {
        throw std::invalid_argument("recursiveBinarySearch: The vector is empty.");
    }

    if (low > high) {
        return -1;
    }

    int mid = low + ((high - low) / 2); // Prevents overflow compared to (high + low) / 2

    if (key == v[mid]) {
        return mid;
    } else if (key < v[mid]) {
        return recursiveBinarySearch(v, low, mid - 1, key);
    } else {
        return recursiveBinarySearch(v, mid + 1, high, key);
    }
}

#endif /* SEARCH_H */