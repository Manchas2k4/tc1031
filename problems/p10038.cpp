#include <iostream>
#include <cmath>
#include <set>

using namespace std;


int main(int argc, char* argv[]) {
  set<int> differences;
  set<int>::const_iterator it;
  int n, i, a, b;
  bool jolly;

  while (cin >> n) {
    differences.clear();

    cin >> a;
    for (i = 2; i <= n; i++) {
      cin >> b;
      differences.insert((int) abs(a - b));
      a = b;
    }

    if ((n - differences.size() != 1)) {
      cout << "Not jolly\n";
      continue;
    }

    a = 1;
    jolly = true;
    for (it = differences.begin(); it != differences.end(); it++) {
      if ((*it) != a++) {
        jolly = false;
        break;
      }
    }
    
    cout << ((jolly)? "Jolly" : "Not jolly") << "\n";
  }
  return 0;
}
