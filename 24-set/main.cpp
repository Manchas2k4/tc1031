#include <iostream>
#include "set.h"

using namespace std;

int main(int argc, char* argv[]) {
  Set<int> a, b, c;

  for (int i = 5; i > 0; i--) {
    a.add(i);
    cout << "a: " << a.toString() << "\n";
  }

  b.add(2); b.add(4); b.add(5);
  cout << "b: " << b.toString() << "\n";

  c = a.join(b);
  cout << "c: " << c.toString() << "\n";

  c = a.intersection(b);
  cout << "c: " << c.toString() << "\n";

  c = a.difference(b);
  cout << "c: " << c.toString() << "\n";
  return 0;
}
