// =================================================================
//
// File: header.h
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//              of the Chronometer class, as well as the
//              implementation of some support functions. This class
//              is used to record the execution time of a program.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <stdexcept> // Para manejo de excepciones

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long int lli;

/**
 * @class Chronometer
 * @brief A class for measuring execution time of code blocks.
 */
class Chronometer {
private:
  timeval startTime; /**< Stores the start time of the chronometer. */
  bool started;      /**< Indicates whether the chronometer has started. */

public:
  /**
   * @brief Default constructor. Initializes the chronometer as not started.
   */
  Chronometer() : started(false) {}

  /**
   * @brief Starts the chronometer.
   */
  void start() {
    started = true;
    gettimeofday(&startTime, NULL);
  }

  /**
   * @brief Stops the chronometer and calculates the elapsed time in milliseconds.
   * 
   * @return The elapsed time in milliseconds. Returns -1 if the chronometer was not started.
   */
  double stop() {
    timeval endTime;
    long seconds, useconds;
    double duration = -1;

    if (started) {
      gettimeofday(&endTime, NULL);

      seconds  = endTime.tv_sec  - startTime.tv_sec;
      useconds = endTime.tv_usec - startTime.tv_usec;

      duration = (seconds * 1000.0) + (useconds / 1000.0);
      started = false;
    }
    return duration;
  }
};

/**
 * @brief Swaps two elements in an array.
 * 
 * @tparam T The type of elements in the array.
 * @param A The array.
 * @param i The index of the first element.
 * @param j The index of the second element.
 * @throw std::out_of_range If `i` or `j` are out of bounds.
 */
template <class T>
void swap(T *A, int i, int j) {
  if (i < 0 || j < 0) {
    throw std::out_of_range("swap: Index cannot be negative.");
  }
  T aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/**
 * @brief Swaps two elements in a vector.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector.
 * @param i The index of the first element.
 * @param j The index of the second element.
 * @throw std::out_of_range If `i` or `j` are out of bounds.
 */
template <class T>
void swap(std::vector<T> &v, int i, int j) {
  if (i < 0 || j < 0 || i >= v.size() || j >= v.size()) {
    throw std::out_of_range("swap: Index out of bounds.");
  }
  T aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

/**
 * @brief Converts an array to a string representation.
 * 
 * @tparam T The type of elements in the array.
 * @param A The array.
 * @param size The size of the array.
 * @return A string representation of the array.
 * @throw std::invalid_argument If the array size is 0 or negative.
 */
template <class T>
std::string arr2str(T *A, int size) {
  if (size <= 0) {
    throw std::invalid_argument("arr2str: Array size must be greater than 0.");
  }

  std::stringstream aux;
  aux << "[" << A[0];
  for (int i = 1; i < size; i++) {
    aux << ", " << A[i];
  }
  aux << "]";
  return aux.str();
}

/**
 * @brief Converts a vector to a string representation.
 * 
 * @tparam T The type of elements in the vector.
 * @param v The vector.
 * @return A string representation of the vector.
 * @throw std::invalid_argument If the vector is empty.
 */
template <class T>
std::string vec2str(const std::vector<T> &v) {
  if (v.empty()) {
    throw std::invalid_argument("vec2str: Vector is empty.");
  }

  std::stringstream aux;
  aux << "[" << v[0];
  for (size_t i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}

#endif /* HEADER_H */