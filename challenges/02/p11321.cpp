#include <iostream>
#include <iomanip>
#include <algorithm>

#define SIZE 10001

using namespace std;

int n, m;

bool compare (int a, int b) {
    if (a % m != b % m) {
        return a % m < b % m;
    }

	if (abs(a % 2) != abs(b % 2)) {
        return abs(a % 2) > abs(b % 2);
    }
    
    if (a % 2 != 0) {
        return a > b;
    }
	
    return a < b;
}

int main(int argc, char* argv[]) {
    int arr[SIZE];

    while (true) {
        cin >> n >> m;

        cout << n << " " << m << "\n";

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n, compare);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\n";
        }

    }
    return 0;
}
