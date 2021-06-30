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
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <string>
#include <vector>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long int lli;

// =================================================================
// This class allows us to calculate the time that elapses between
// one execution line and another.
// =================================================================
class Chronometer {
private:
  timeval startTime;
  bool 	started;

public:
  Chronometer() :started(false) {}

  void start(){
    started = true;
    gettimeofday(&startTime, NULL);
  }

  double stop(){
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
std::string arr2str(T *A, int size) {
  std::stringstream aux;

  aux << "[" << A[0];
  for (int i = 1; i < size; i++) {
    aux << ", " << A[i];
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

  aux << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}

#endif
