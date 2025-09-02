#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int n, aux;
    list<int> lst;
    list<int>::iterator itr;
    double avg, variance, std;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        lst.push_back(aux);
    }

    lst.sort();
    for (itr = lst.begin(); itr != lst.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << "\n";

    lst.reverse();
    for (itr = lst.begin(); itr != lst.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << "\n";

    avg = 0;
    for (itr = lst.begin(); itr != lst.end(); itr++) {
        avg = avg + (*itr);
    }
    avg = avg / lst.size();

    variance = 0;
    for (itr = lst.begin(); itr != lst.end(); itr++) {
        variance = variance + (((*itr) - avg) * ((*itr) - avg));
    }
    variance = variance / lst.size();

    std = sqrt(variance);

    cout << "avg = " << avg << "\n";
    cout << "variance = " << variance << "\n";
    cout << "std = " << std << "\n";

    return 0;
}
