// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				bubble sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>
#include "header.h"
#include "insertion.h"

using namespace std;

void fillArray(int *A, int size) {
  for (int i = 0; i < size - 1; i++) {
    //A[i] = size - i + 1;
    A[i] = i;
  }
}

int main(int argc, char* argv[]) {
  int *arr;
  int size = 1000;
  Chronometer c;
  double ms;

  for (int i = 0; i < 3; i++) {
    cout << "Starting size = " << size <<  "...";
    arr = new int[size];
    fillArray(arr, size);
    c.start();
    insertionSort(arr, size);
    ms = c.stop();
    cout<< " time = " << ms << " ms\n";
    delete [] arr;
    size *= 10;
  }
  return 0;
}
