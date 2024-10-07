// =================================================================
//
// File: iterative.cpp
// Author: Pedro Perez
// Description: This file implements the solution for the problem:
//				given an array A[] of n numbers and another number
//				x, determines whether or not there exist two
//				elements in S whose sum is exactly x.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

// =================================================================
// Given an array, arr, determine whether there are two numbers
// whose exact sum is X.
//
// @param arr, an array of integer numbers.
// @param n, the size of the array
// @param x, the sum
// @return True, if there are two elements within the array whose
//				 sum is x. False otherwise.
// =================================================================
bool exactSum(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ( (arr[i] + arr[j]) == x ) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	int A[] = { 1, 4, 45, 6, 10, -8 };
	int n = 6;
	int x = 16;

	if (exactSum(A, n, x)) {
		std::cout << "Array has two elements with given sum\n";
	} else {
		std::cout << "Array doesn't have two elements with given sum\n";
	}
	return 0;
}
