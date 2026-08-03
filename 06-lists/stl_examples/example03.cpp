#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

list<int> createList(int size) {
    list<int> result;

    srand(time(0));
    for (int i = 0; i < size; i++) {
        result.push_back( (rand() % 100) + 1 );
    }
    result.sort();
    return result;
}

void displayList(const char *text, const list<int> &lst) {
    cout << text << ":";
    if (!lst.empty()) {
        auto it = lst.begin();
        cout << "[" << *it; it++;
        for (; it != lst.end(); it++) {
            cout << ", " << *it;
        }
    }
    cout << "]\n";
}

template <class T>
list<T> unionList(const list<T> &l1, const list<T> &l2) {
    list<T> result(l1);

    for (auto val : l2) {
        if (!binary_search (l1.begin(), l1.end(), val)) {
            result.push_back(val);
        }
    }
    return result;
}

template <class T>
list<T> intersectionList(const list<T> &l1, const list<T> &l2) {
    list<T> result;

    for (auto val : l1) {
        if (binary_search (l2.begin(), l2.end(), val)) {
            result.push_back(val);
        } 
    }
    return result;
}

template <class T> 
list<T> filter(const list<T> &lst, bool (*fn) (T)) {
    list<T> result;

    for (auto it = lst.begin(); it != lst.end(); it++) {
        if (fn( *it )) {
            result.push_back(*it);
        }
    }
    return result;
}

template <class T>
list<T> mergeList(const list<T> &l1, const list<T> &l2) {
    list<T> result;
    auto i = l1.begin();
    auto j = l2.begin();

    while (i != l1.end() && j != l2.end()) {
        if (*i < *j) {
            result.push_back(*i);
            i++;
        } else {
            result.push_back(*j);
            j++;
        }
    }

    while (i != l1.end()) {
        result.push_back(*i);
        i++;
    }

    while (j != l2.end()) {
        result.push_back(*j);
        j++;
    }

    return result;
}

bool isEven(int a) {
    return (a % 2 == 0);
}

bool isMoreThan50(int a) {
    return (a > 50);
}

int main(int argc, char* argv[]) {
    srand(time(0));

    list<int> l1 = createList(10);
    list<int> l2 = createList(7);

    displayList("l1", l1);
    displayList("l2", l2);

    list<int> l3 = unionList(l1, l2);
    displayList("unionList",l3);
    list<int> l4 = intersectionList(l1, l2);
    displayList("intersectionList", l4);

    list<int> l5 = filter(l1, isEven);
    displayList("filter even", l5);
    list<int> l6 = filter(l1, isMoreThan50);
    displayList("filter >50 ", l6);

    list<int> l7 = mergeList(l1, l2);
    displayList("merge", l7);

    return 0;
}