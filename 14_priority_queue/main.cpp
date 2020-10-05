#include <iostream>
#include <cstdlib>
#include "pqueue.h"

using namespace std;

int main(int argc, char* argv[]) {
  PriorityQueue<int> pq;

  srand(1234);
  for (int i = 0; i < 10; i++) {
    pq.enqueue(rand() % 100 + 1);
    cout << pq.toString() << "\n";
  }

  while(!pq.empty()) {
    cout << pq.front() << "\n";
    pq.dequeue();
  }
  return 0;
}
