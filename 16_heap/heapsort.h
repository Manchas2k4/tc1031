// =================================================================
//
// File: bubble.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				bubble sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "header.h"

using namespace std;

int parent(int pos) {
	return (pos - 1) / 2;
}

int left(int pos) {
	return (pos * 2) + 1;
}

int right(int pos) {
	return (pos * 2) + 2;
}

template <class T>
void heapify(T *arr, int size, int pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint min = pos;

	if(le < size && arr[le] > arr[min]){
			min = le;
	}
	if(ri < size && arr[ri] > arr[min]){
			min = ri;
	}

	if(min != pos){
			swap(arr, pos, min);
			heapify(arr, size, min);
	}
}

template <class T>
void buildMaxHeap(T *arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

// =================================================================
// Performs the heap sort algorithm.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void heapSort(T *arr, int size) {
	int max = size, i;

	buildMaxHeap(arr, max);
	for (i = size - 1; i > 0; i--) {
		swap(arr, i, 0);
		max--;
		heapify(arr, max, 0);
	}
}

#endif /* HEAPSORT_H */
