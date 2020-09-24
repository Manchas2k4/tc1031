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
// =================================================================
#include "header.h"
#include "search.h"
#include <vector>

using namespace std;

const int SIZE = 1000000000;

int main(int argc, char* argv[]) {
  Chronometer c;
	double ms;
  vector<int> v(SIZE);
  int result;

  for (int i = 0; i < SIZE; i++) {
    v[i] = (i + 1);
  }

  cout << "Starting sequential\n";
  c.start();
  result = sequentialSearch(v, 0);
  ms = c.stop();
  cout << "result = " << result << "\n";
  cout << "time = " << ms << " ms\n";

  cout << "Starting binary\n";
  c.start();
  result = binarySearch(v, 0);
  ms = c.stop();
  cout << "result = " << result << "\n";
  cout << "time = " << ms << " ms\n";

  cout << "Starting binaryR\n";
  c.start();
  result = binaryRSearch(v, 0, v.size(), 0);
  ms = c.stop();
  cout << "result = " << result << "\n";
  cout << "time = " << ms << " ms\n";
  return 0;
}
