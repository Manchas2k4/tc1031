#include <iostream>
#include <iomanip>

#define SIZE 100005

int left_neighbor[SIZE];
int right_neighbor[SIZE];

using namespace std;

int main(int argc, char* argv[]) {
    int s, b, le, ri;

    while (true) {
        cin >> s >> b;

        if (s == 0 || b == 0) {
            break;
        }

        for (int k = 1; k <= s; k++) {
            left_neighbor[k] = k - 1;
            right_neighbor[k] = k + 1;
        }
        right_neighbor[s] = -1;
        left_neighbor[1] = -1;

        le = 0; ri = 0;
        for (int k = 0; k < b; k++) {
            cin >> le >> ri;

            left_neighbor[right_neighbor[ri]] = left_neighbor[le];
            if (left_neighbor[le] != -1) {
                cout << left_neighbor[le];
            } else {
                cout << "*";
            }

            right_neighbor[left_neighbor[le]] = right_neighbor[ri];
            if (right_neighbor[ri] != -1) {
                cout << " " << right_neighbor[ri] << "\n";
            } else {
                cout << " *\n";
            }
        }
        cout << "-\n";
    }

    return 0;
}