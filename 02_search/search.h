// =================================================================
//
// File: search.h 
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				sequential and binary search algorithms. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================

#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

template <class T>
int sequentialSearch(T *A, int size, T key) {
	for (int i = 0; i < size; i++) {
		if (A[i] == key) {
			return i;
		}
	}
	return -1;
}

template <class T>
int binarySearch(T *A, int size, T key) {
	int low, high, mid;
	
	low = 0;
	high = size - 1;
	while (low <= high) {
		mid = low + ((high - low) / 2);
		if (key == A[mid]) {
			return mid;
		} else if (key < A[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}