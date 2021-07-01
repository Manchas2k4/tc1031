// =================================================================
//
// File: recursion02.cpp
// Author: Pedro Perez
// Description: This file contains the code that given an array arr
//				of size N and an integer X. The task is to find all
//				the indices of the integer X in the array.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstring>

// =================================================================
// Find, recursively, all occurrences of the number X in the
// array arr.
//
// @param arr, an array of integer numbers.
// @param pos, the current position in the array (from right to left).
// @param x, the searched number.
// =================================================================
void findOcurrences(int arr[], int pos, int x) {
	if (pos == 0) {
		if (arr[pos] == x) {
			std::cout << pos;
		}
		std::cout << "\n";
	} else {
		if (arr[pos] == x) {
			std::cout << pos << " ";
		}
		findOcurrences(arr, pos - 1, x);
	}
}

void findAllOcurrences(int arr[], int size, int x) {
	findOcurrences(arr, size, x);
}

int main(int argc, char* argv[]) {
	int arr[] = {1, 2, 3, 2, 2, 5};
	int x = 2;

	findAllOcurrences(arr, 6, x);
	return 0;
}
