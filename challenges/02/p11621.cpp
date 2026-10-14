#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

typedef unsigned long int ulint;

using namespace std;

vector<ulint> generate_data() {
    vector<ulint> values(1089);

    int k = 0;
    for (int i = 0; i <= 32; i++) {
        for (int j = 0; j <= 32; j++) {
            values[k++] = pow(2, i) * pow(3, j);
        }
    }
    return values;
}

int main(int argc, char* argv[]) {
    vector<ulint> v;
    int m;
    
    v = generate_data();
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    while (true) {
        cin >> m;

        if (m == 0) {
            break;
        }

        cout << *(upper_bound(v.begin(), v.end(), m - 1)) << endl;
    }
    return 0;
}