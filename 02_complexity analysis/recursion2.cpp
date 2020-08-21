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

using namespace std;

void findOcurrences(int arr[], int size, int pos, int x) {
	if (pos == size - 1) {
		if (arr[pos] == x) {
			cout << pos;
		}
		cout << "\n";
	} else {
		if (arr[pos] == x) {
			cout << pos << " ";
		}
		findOcurrences(arr, size, pos + 1, x);
	}
}

void findAllOcurrences(int arr[], int size, int x) {
	findOcurrences(arr, size, 0, x);
}

int main(int argc, char* argv[]) {
	int arr[] = {1, 2, 3, 2, 2, 5};
	int x = 2;
	
	findAllOcurrences(arr, 6, x); 
	return 0;
}