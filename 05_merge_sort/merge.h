// =================================================================
//
// File: insertion.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				merge sort. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <cstring>
#include "header.h"

using namespace std;

template <class T>
void copyArray(T *A, T *B, int low, int high) {
	int size = high - low + 1;
	memcpy(A + low, B + low, sizeof(T) * size);
}

template <class T>
void merge(T *A, T *B, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        }else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    for(; j <= high; j++){
        B[k++] = A[j];
    }

	for(; i <= mid; i++){
        B[k++] = A[i];
    }
}

template<class T>
void split(T *A, T *B, int low, int high) {
    int  mid, size, i, j;

	if (high - low == 0) return;
	
    mid = low + ((high - low) / 2);
    split(A, B, low, mid);
    split(A, B, mid +1, high);
    merge(A, B,low, mid, high);
    copyArray(A, B, low, high);
}

template <class T>
void mergeSort(T *A, int size) {
	T *B = new T[size];
	split(A, B, 0, size - 1);
	delete [] B;
}

#endif