#include <iostream>
#include <vector>
#include "header.h"

lli fiboIterative(int n) {
  lli a, b, aux;

  if (n == 1 || n == 2) {
    return 1;
  }

  a = 1;
  b = 1;
  for (int i = 3; i <= n; i++) {
    aux = a + b;
    a = b;
    b = aux;
  }
  return aux;
}

lli fiboMemoization(int n) {
  std::vector<lli> arr(n + 1);gg

  if (n == 1 || n == 2) {
    return 1;
  }

  arr[1] = 1;
  arr[2] = 1;
  for (int i = 3; i <= n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
}

lli fiboRecursive(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return fiboRecursive(n - 1) + fiboRecursive(n - 2);
  }
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative fibonacci(40): " << fiboIterative(40) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive fibonacci(40): " << fiboRecursive(40) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
