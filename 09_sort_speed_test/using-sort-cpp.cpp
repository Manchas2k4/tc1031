#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility> 
#include <cstdlib>

using namespace std;

typedef pair<int, int> Point;

bool compare1(const Point &left, const Point &right) {
    if (left.first == right.first) {
        return left.second < right.second;
    } else {
        return left.first < right.first;
    }
}

bool compare2(const Point &left, const Point &right) {
    if (left.second == right.second) {
        return left.first < right.first;
    } else {
        return left.second < right.second;
    }
}

int main(int argc, char* argv[]) {
    vector<Point> v(20);

    srand(1234);
    for (int i = 0; i < v.size(); i++) {
        v[i] = make_pair(rand() % 20, rand() % 20);
        cout << i << " = (" << v[i].first << "," << v[i].second << ")\n";
    }

    sort(v.begin(), v.end(), compare1);

    cout << "\n\n";
    for (auto p : v) {
        cout << "(" << p.first << "," << p.second << ")\n";
    }

    sort(v.begin(), v.end(), compare2);

    cout << "\n\n";
    for (auto p : v) {
        cout << "(" << p.first << "," << p.second << ")\n";
    }
}

