#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

template <class T>
void bubbleSort(T *arr, int size) {
	for(int i = size - 1; i > 0; i--){
		for(int j = 0;  j < i; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr, j, j + 1);
			}
		}
	}
}

template <class T>
void bubbleSort(vector<T> &v) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0;  j < i; j++){
			if(v[j] > v[j + 1]){
				swap(v, j, j + 1);
			}
		}
	}
}