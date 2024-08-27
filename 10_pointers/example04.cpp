#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
void swap(T *array, int i, int j) {
    T aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

template <class T>
void bubbleSort(T *arr, int size, 
            bool (*fn) (const T&, const T&)) {
	for(int i = size - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if( fn(arr[j], arr[j + 1]) ){
				swap(arr, j, j + 1);
			}
		}
	}
}

class Point {
public:
    int x, y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

bool ordenar(const Point &a, const Point &b) {
    if (a.x == b.x) {
        return a.y > b.y;
    } else {
        return a.x > b.x;
    }
}

bool ordenar2(const Point &a, const Point &b) {
    if (a.y == b.y) {
        return a.y > b.y;
    } else {
        return a.y < b.y;
    }
}

int main(int argc, char* argv[]) {
    Point arr1[] = {Point(12, 40), Point(44, 19),
        Point(27, 8), Point(44, 10), Point(12, 10)};

    bubbleSort(arr1, 5, ordenar);
    for (int i = 0; i < 5; i++) {
        cout << "(" << arr1[i].x << ", " 
            << arr1[i].y << ") ";
    } 
    cout << "\n";

    bubbleSort(arr1, 5, ordenar2);
    for (int i = 0; i < 5; i++) {
        cout << "(" << arr1[i].x << ", " 
            << arr1[i].y << ") ";
    } 
    cout << "\n";

    return 0;
}

