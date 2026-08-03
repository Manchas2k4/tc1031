// =================================================================
//
// File: speed.cpp
// Author: Pedro Perez
// Description: This file contains the code to perform speed tests
//				on the various sorting algorithms that we have seen.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include "..\utils\header.h"
#include "sorts.h"
#include "..\utils\generator.h"

using namespace std;
using namespace std::chrono;

const int DISPLAY   = 100;
const int TOP_VALUE = 10000;
const int SIZE		= 100000;

void theWorseCase(vector<int> &v) {
	int size = v.size();

	for (int i = 0; i < v.size(); i++) {
		v[i] = (size - i);
		//v[i] = Generator::randomNumber(1, TOP_VALUE);
	}
}

void display(const char *text, const std::vector<int> &v) {
	if (v.empty()) {
    	throw std::invalid_argument("display: Vector is empty.");
  	}

	std::stringstream aux;
	aux << text << " = [" << v[0];
	for (size_t i = 1; i < DISPLAY; i++) {
		aux << ", " << setw(6) << v[i];
	}
	aux << "]\n";
	
	cout << aux.str();
}

int main(int argc, char* argv[]) {
	vector<int> source(SIZE);

	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	timeElapsed = 0;
	theWorseCase(source);
	cout << "BUBBLE SORT\n";
	display("before", source);
	start = high_resolution_clock::now();
	bubbleSort(source);
	end = high_resolution_clock::now();
	timeElapsed = duration<double, std::milli>(end - start).count();
	display("after", source);
	cout << "time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source);
	cout << "\n\nSELECTION SORT\n";
	display("before", source);
	start = high_resolution_clock::now();
	selectionSort(source);
	end = high_resolution_clock::now();
	timeElapsed = duration<double, std::milli>(end - start).count();
	display("after", source);
	cout << "time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source);
	cout << "\n\nINSERTION SORT\n";
	display("before", source);
	start = high_resolution_clock::now();
	insertionSort(source);
	end = high_resolution_clock::now();
	timeElapsed = duration<double, std::milli>(end - start).count();
	display("after", source);
	cout << "time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source);
	cout << "\n\nMERGE SORT\n";
	display("before", source);
	start = high_resolution_clock::now();
	mergeSort(source);
	end = high_resolution_clock::now();
	timeElapsed = duration<double, std::milli>(end - start).count();
	display("after", source);
	cout << "time = " << setprecision(15) << timeElapsed << " ms" << endl;

	timeElapsed = 0;
	theWorseCase(source);
	cout << "\n\nQUICK SORT\n";
	display("before", source);
	start = high_resolution_clock::now();
	cout << "before\n";
	quickSort(source);
	cout << "after\n";
	end = high_resolution_clock::now();
	timeElapsed = duration<double, std::milli>(end - start).count();
	display("after", source);
	cout << "avg time = " << setprecision(15) << timeElapsed << " ms" << endl;

}
