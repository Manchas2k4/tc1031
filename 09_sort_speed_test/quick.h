// =================================================================
//
// File: quick.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				quick sort. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include "header.h"

using namespace std;

template <class T>
int find_pivot(T *A, int low, int high) {
	int i;
	
	for (i = low + 1; i <= high; i++) {
		if (A[low] > A[i]) {
			return A[low];
		} else if (A[low] < A[i]){
			return A[i];
		}
	}
	return -1;
}

template <class T>
int make_partition(T *A, int low, int high, int pivot) {
	int i, j;
	
	i = low;
	j = high;
	while (i < j) {
		swap(A, i , j);
		while (A[i] < pivot) {
			i++;
		}
		while (A[j] >= pivot) {
			j--;
		}
	}
	return i;
}

template <class T>
void quick(T *A, int low, int high) {
	int pivot, pos;
	
	pivot = find_pivot(A, low, high);
	if (pivot != -1) {
		pos = make_partition(A, low, high, pivot);
		quick(A, low, pos - 1);
		quick(A, pos, high);
	}
}

template <class T>
void quickSort(T *A, int size) {
	quick(A, 0, size - 1);
}

#endif