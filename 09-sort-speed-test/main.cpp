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
#include <chrono>

using namespace std;
using namespace std::chrono;

const int DISPLAY = 100;
const int TOP_VALUE = 10000;
const int SIZE = 75000;

void theWorseCase(int *array, int size) {
	int i;

	srand(time(0));
	for (i = 0; i < size; i++) {
		array[i] = (size - i);
		//array[i] = rand() % TOP_VALUE;
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
	int *source = new int[SIZE];

	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	timeElapsed = 0;
	theWorseCase(source, SIZE);
	cout << "BUBBLE SORT\n";
	displayArray("before", source);
	start = high_resolution_clock::now();
	bubbleSort(source, SIZE);
	end = high_resolution_clock::now();
	timeElapsed = 
			duration<double, std::milli>(end - start).count();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source, SIZE);
	cout << "\n\nSELECTION SORT\n";
	displayArray("before", source);
	start = high_resolution_clock::now();
	selectionSort(source, SIZE);
	end = high_resolution_clock::now();
	timeElapsed = 
			duration<double, std::milli>(end - start).count();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source, SIZE);
	cout << "\n\nINSERTION SORT\n";
	displayArray("before", source);
	start = high_resolution_clock::now();
	insertionSort(source, SIZE);
	end = high_resolution_clock::now();
	timeElapsed = 
			duration<double, std::milli>(end - start).count();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source, SIZE);
	cout << "\n\nMERGE SORT\n";
	displayArray("before", source);
	start = high_resolution_clock::now();
	mergeSort(source, SIZE);
	end = high_resolution_clock::now();
	timeElapsed = 
			duration<double, std::milli>(end - start).count();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source, SIZE);
	cout << "\n\nQUICK SORT\n";
	displayArray("before", source);
	start = high_resolution_clock::now();
	quickSort(source, SIZE);
	end = high_resolution_clock::now();
	timeElapsed = 
			duration<double, std::milli>(end - start).count();
	displayArray("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

	delete [] source;
}
