#include <iostream>
#include "heap.h"
#include "heapsort.h"

using namespace std;

int main(int argc, char* argv[]) {
  int numbers[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55};
  Heap<int> heap(20);

  /*
  for (int i = 0; i < 12; i++) {
    heap.add(numbers[i]);
    cout << heap.toString() << "\n";
  }
  cout << heap.remove() << "\n";
  cout << heap.toString() << "\n\n";

  cout << heap.remove() << "\n";
  cout << heap.toString() << "\n\n";

  cout << heap.remove() << "\n";
  cout << heap.toString() << "\n\n";
  */

  cout << "before: " << arr2str(numbers, 12) << "\n";
  heapSort(numbers, 12);
  cout << "after: " << arr2str(numbers, 12) << "\n";

  return 0;
}
