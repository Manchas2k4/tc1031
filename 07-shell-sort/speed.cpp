// =================================================================
//
// File: speed.cpp
// Author: Pedro Perez
// Description: In this file, we check the speed of the insertion
//              sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#include <iostream>
#include <chrono>
#include "header.h"
#include "shell.h"

using namespace std;
using namespace std::chrono;

void fillArray(int *A, int size) {
  for (int i = 0; i < size - 1; i++) {
    //A[i] = size - i + 1;
    A[i] = i;
  }
}

int main(int argc, char* argv[]) {
  int *arr;
  int size = 1000;
  
  // These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

  for (int i = 0; i < 4; i++) {
    cout << "Starting size = " << size <<  "...";
    arr = new int[size];
    fillArray(arr, size);
    
    start = high_resolution_clock::now();
    
    shellSort(arr, size);
    
    end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();

    cout << "time = " << timeElapsed << " ms\n";

    delete [] arr;
    
    size *= 10;
  }
  return 0;
}
