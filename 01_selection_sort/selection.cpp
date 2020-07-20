#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

template <class T>
void selectionSort(T *arr, int size) {
	int pos;
	
	for(int i = size - 1; i > 0; i--){
        pos = 0;
        for(int j = 1; j <= i; j++){
            if(arr[j] > arr[pos]){
                pos = j;
            }
        }

        if (pos != i){
            swap(arr, i, pos);
        }
    }
}

template <class T>
void selectionSort(vector<T> &v) {
	int pos;
	
	for(int i = v.size() - 1; i > 0; i--){
        pos = 0;
        for(int j = 1; j <= i; j++){
            if(v[j] > v[pos]){
                pos = j;
            }
        }

        if (pos != i){
            swap(v, i, pos);
        }
    }
}