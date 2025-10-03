// =================================================================
//
// File: header.h
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the Chronometer class, as well as the
//				implementation of some support functions. This class
//				is used to record the execution time of a program.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <random>
#include <chrono>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long int lli;

const int DISPLAY   = 50;
const int TOP_VALUE = 10000;

// =================================================================
// Swap the content of two localities (i, j) in array A.
//
// @param A, an array of T elements.
// @param i, an index in the array.
// @param j, an index in the array.
// =================================================================
template <class T>
void swap(T *A, int i, int j) {
    T aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}

// =================================================================
// Swap the content of two localities (i, j) in vector v.
//
// @param v, a vector of T elements.
// @param i, an index in the vector.
// @param j, an index in the vector.
// =================================================================
template <class T>
void swap(std::vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// =================================================================
// Converts the content of an array to a string.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
std::string arr2str(T *A, uint size) {
    std::stringstream aux;
    int minimum;

    minimum = MIN(size, DISPLAY);
    aux << "[";
    if (size > 0) {
        aux << A[0];
    }
    for (int i = 1; i < minimum; i++) {
        aux << ", " << A[i];
    }
    if (minimum >= DISPLAY) {
        aux << " ...";
    }
    aux << "]";
    return aux.str();
}

// =================================================================
// Converts the content of a vector to a string.
//
// @param v, a vector of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
std::string vec2str(const std::vector<T> &v) {
    std::stringstream aux;
    int minimum;

    minimum = MIN(v.size(), DISPLAY);
    aux << "[";
    if (v.size() > 0) {
        aux << v[0];
    }
    for (int i = 1; i < minimum; i++) {
        aux << ", " << v[i];
    }
    if (minimum >= DISPLAY) {
        aux << " ...";
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string lst2str(const std::list<T> &lst) {
    std::stringstream aux;
    int i, minimum;

    aux << "[";
    if (!lst.empty()) {
        auto it = lst.begin();
        aux << *it; it++;

        i = 0;
        minimum = MIN(lst.size(), DISPLAY);
        while (i < minimum) {
            aux << ", " << *it;
            i++;
            it++;
        }

        if (minimum >= DISPLAY) {
            aux << " ...";
        }
    }
    aux << "]";
    return aux.str();
}

// =================================================================
// Initializes an array with random values between 1 and TOP_VALUE.
//
// @param array, an array of integer numbers.
// @param size, the amount of numbers.
// =================================================================
void random_array(int *array, int size) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, TOP_VALUE);

    for (int i = 0; i < size; i++) {
        array[i] = distribution(generator);
    }
}


void random_vector(std::vector<int> &array) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, TOP_VALUE);

    for (int i = 0; i < array.size(); i++) {
        array[i] = distribution(generator);
    }
}

void random_list(std::list<int> &lst, int size) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, TOP_VALUE);

    for (int i = 0; i < size; i++) {
        lst.push_back(distribution(generator));
    }
}

#endif
