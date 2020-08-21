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

// =================================================================
// Find the pivot to be used for separation
// 
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// @return the pivot number, otherwise it returns -1.
// =================================================================
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

// =================================================================
// Separate the elements. On the left side of the range [low, high] 
// places the elements that are less than the pivot; on the right 
// side, the elements that are greater than or equal to the pivot.
// 
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// @return the point where elements greater than or equal to the 
//		   pivot begin.
// =================================================================
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

// =================================================================
// If there is a pivot, it separates the elements.
// 
// @param A, the destination array.
// @param low, lower index.
// @param high, higher index.
// =================================================================
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

// =================================================================
// Performs the quick sort algorithm.
// 
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void quickSort(T *A, int size) {
	quick(A, 0, size - 1);
}

#endif /* QUICKSORT_H */