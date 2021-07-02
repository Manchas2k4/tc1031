// =================================================================
//
// File: heapsort.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				heap sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "header.h"
#include <vector>

// =================================================================
// Returns the position of the parent of an element.
//
// @returns the index of the parent
// =================================================================
int parent(int pos) {
	return (pos - 1) / 2;
}

// =================================================================
// Returns the position of the left child of an element.
//
// @returns the index of the left child.
// =================================================================
int left(int pos) {
	return (pos * 2) + 1;
}

// =================================================================
// Returns the position of the right child of an element.
//
// @returns the index of the right child.
// =================================================================
int right(int pos) {
	return (pos * 2) + 2;
}

// =================================================================
// HEAP SORT - ARRAY VERSION
// =================================================================
// =================================================================
// Place the item in the correct position. In this case, since it is
// a max-heap, its children must be less than the element.
//
// @param arr, an array of T elements.
// @param size, the number of unordered elements.
// @param pos, position to be checked.
// =================================================================
template <class T>
void heapify(T *arr, int size, int pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint max = pos;

	if(le < size && arr[le] > arr[max]){
		max = le;
	}
	if(ri < size && arr[ri] > arr[max]){
		max = ri;
	}

	if(max != pos){
		swap(arr, pos, max);
		heapify(arr, size, max);
	}
}

// =================================================================
// Builds a max-heap from an initial array.
//
// @param arr, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void buildMaxHeap(T *arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

// =================================================================
// Performs the heap sort algorithm.
//
// @param arr, an array of T elements.
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

// =================================================================
// HEAP SORT - VECTOR VERSION
// =================================================================
// =================================================================
// Place the item in the correct position. In this case, since it is
// a max-heap, its children must be less than the element.
//
// @param arr, a vector of T elements.
// @param size, the number of unordered elements.
// @param pos, position to be checked.
// =================================================================
template <class T>
void heapify(std::vector<T> &arr, int size, int pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint max = pos;

	if(le < size && arr[le] > arr[max]){
		max = le;
	}
	if(ri < size && arr[ri] > arr[max]){
		max = ri;
	}

	if(max != pos){
		swap(arr, pos, max);
		heapify(arr, size, max);
	}
}

// =================================================================
// Builds a max-heap from an initial vector.
//
// @param arr, a vector of T elements.
// @param size, the number of unordered elements.
// =================================================================
template <class T>
void buildMaxHeap(std::vector<T> &arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

// =================================================================
// Performs the heap sort algorithm.
//
// @param arr, a vector of T elements.
// =================================================================
template <class T>
void heapSort(std::vector<T> &arr) {
	int i, max;

	max = arr.size() - 1;
	buildMaxHeap(arr, max);
	for (i = arr.size() - 1; i > 0; i--) {
		swap(arr, i, 0);
		max--;
		heapify(arr, max, 0);
	}
}
#endif /* HEAPSORT_H */
