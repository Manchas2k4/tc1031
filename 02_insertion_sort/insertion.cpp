#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

template <class T>
void insertionSort(T *arr, int size) {
	for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
            swap(arr, j, j - 1);
        }
	}
}

template <class T>
void insertionSort(vector<T> &v) {
	for(int i = 1; i < v.size(); i++){
        for(int j = i; j > 0 && v[j] < v[j - 1]; j--){
            swap(v, j, j - 1);
        }
	}
}