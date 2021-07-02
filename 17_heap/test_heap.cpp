#include <iostream>
#include "heap.h"

int main(int argc, char* argv[]) {
  //int numbers[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55};
  Heap<int> heap(20);

  /*
  for (int i = 0; i < 12; i++) {
    heap.add(numbers[i]);
    std::cout << heap.toString() << "\n";
  }
  */

  heap.add(10);
  std::cout << heap.toString() << "\n";
  heap.add(1);
  std::cout << heap.toString() << "\n";
  heap.add(5);
  std::cout << heap.toString() << "\n";

  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  std::cout << "remove = " << heap.remove() << "\n";
  std::cout << heap.toString() << "\n";
  return 0;
}
