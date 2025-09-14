// =================================================================
//
// File: shell.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				shell sort.
//
// Copyright (c) 2025 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SHELL_H
#define SHELL_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the shell sort algorith on an array.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void shellSort(T *arr, int size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < size; i++){
			int j, temp = arr[i];
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

// =================================================================
// Performs the shell sort algorith on a vector.
//
// @param A, a vector of T elements.
// =================================================================
template <class T>
void shellSort(std::vector<T> &v) {
	for (int gap = v.size() / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < v.size(); i++){
			int j, temp = v[i];
			for(j = i; j >= gap && v[j - gap] > temp; j -= gap){
				v[j] = v[j - gap];
			}
			v[j] = temp;
		}
	}
}

#endif /* SHELL_H */
