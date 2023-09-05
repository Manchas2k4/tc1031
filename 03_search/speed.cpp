// =================================================================
//
// File: speed_test.cpp
// Author: Pedro Perez
// Description: This file implements various tests on the
//				implemented code.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================h"
#include <chrono>
#include <vector>
#include "header.h"
#include "search.h"

const int SIZE = 1000000000;

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
  std::vector<int> v(SIZE);
  int result;

  // These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

  for (int i = 0; i < SIZE; i++) {
    v[i] = (i + 1);
  }

  cout << "Starting sequential\n";
  
  start = high_resolution_clock::now();
  result = sequentialSearch(v, 0);
  end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();

  cout << "result = " << result << "\n";
  cout << "time = " << timeElapsed << " ms\n";

  std::cout << "Starting binary\n";
  start = high_resolution_clock::now();
  result = binarySearch(v, 0);
  end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();

  cout << "result = " << result << "\n";
  cout << "time = " << timeElapsed << " ms\n";

  cout << "Starting binaryR\n";
  start = high_resolution_clock::now();
  result = binaryRSearch(v, 0, v.size(), 0);
  end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();

  cout << "result = " << result << "\n";
  cout << "time = " << timeElapsed << " ms\n";
  
  return 0;
}
