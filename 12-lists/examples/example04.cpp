#include <iostream>
#include <iomanip>
#include <chrono>
#include <list>
#include "header.h"
#include "merge.h"

using namespace std;
using namespace std::chrono;

const int SIZE = 10000000;

void random_data(vector<int> &v, list<int> &lst, int size) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, TOP_VALUE);

    v.resize(size);
    for (int i = 0; i < size; i++) {
        int aux = distribution(generator);
        v[i] = aux;
        lst.push_back(aux);
    }
}

template <class T>
list<T> quickSortV1(const list<T> &lst) {
    if (lst.size() <= 1) {
        return lst;
    }

    auto pivot = lst.front();
    list<T> less, equal, greater;

    for (T val : lst) {
        if (val < pivot) {
            less.push_back(val);
        } else if (val == pivot) {
            equal.push_back(val);
        } else {
            greater.push_back(val);
        }
    }

    less = quickSortV1(less);
    greater = quickSortV1(greater);

    less.splice(less.end(), equal);
    less.splice(less.end(), greater);

    return less;
}

int main(int argc, char* argv[]) {
    high_resolution_clock::time_point start, end;
    double timeElapsed;
    list<int> lst, result;
    vector<int> v;

    random_data(v, lst, SIZE);

    cout << "v = " << vec2str(v) << "\n";
    cout << "lst1 = " << lst2str(lst) << "\n";

    timeElapsed = 0;
    start = high_resolution_clock::now();
    mergeSort(v);
    end = high_resolution_clock::now();
    timeElapsed = duration<double, std::milli>(end - start).count();
    cout << "\nordered vector = " << vec2str(v) << "\n";
    cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

    timeElapsed = 0;
    start = high_resolution_clock::now();
    result = quickSortV1(lst);
    end = high_resolution_clock::now();
    timeElapsed = duration<double, std::milli>(end - start).count();
    cout << "\nquick sort v1 = " << lst2str(result) << "\n";
    cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

    return 0;
}