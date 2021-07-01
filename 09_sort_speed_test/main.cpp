// =================================================================
//
// File: main.cpp
// Author: Pedro Perez
// Description: This file contains the code to perform speed tests
//				on the various sorting algorithms that we have seen.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int DISPLAY = 100;
const int TOP_VALUE = 10000;
const int SIZE = 75000;

void theWorseCase(int *array, int size) {
	int i;

	srand(time(0));
	for (i = 0; i < size; i++) {
		array[i] = (size - i);
	}
}

void displayArray(const char *text, int *array) {
	int i;

	printf("%s = [%4i", text, array[0]);
	for (i = 1; i < DISPLAY; i++) {
		printf(",%4i", array[i]);
	}
	printf(", ... ,]\n");
}

int main(int argc, char* argv[]) {
	Chronometer c;
	double ms;
	int *source = new int[SIZE];

	theWorseCase(source, SIZE);
	cout << "BUBBLE SORT\n";
	displayArray("before", source);
	c.start();
	bubbleSort(source, SIZE);
	ms = c.stop();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << ms << " ms" << endl;

	theWorseCase(source, SIZE);
	cout << "\n\nSELECTION SORT\n";
	displayArray("before", source);
	c.start();
	selectionSort(source, SIZE);
	ms = c.stop();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << ms << " ms" << endl;

	theWorseCase(source, SIZE);
	cout << "\n\nINSERTION SORT\n";
	displayArray("before", source);
	c.start();
	insertionSort(source, SIZE);
	ms = c.stop();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << ms << " ms" << endl;

	theWorseCase(source, SIZE);
	cout << "\n\nMERGE SORT\n";
	displayArray("before", source);
	c.start();
	mergeSort(source, SIZE);
	ms = c.stop();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << ms << " ms" << endl;

	theWorseCase(source, SIZE);
	cout << "\n\nQUICK SORT\n";
	displayArray("before", source);
	c.start();
	quickSort(source, SIZE);
	ms = c.stop();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << ms << " ms" << endl;

	delete [] source;
}
