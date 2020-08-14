// =================================================================
//
// File: digits.cpp
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of a function to find the sum of
//				digits of a number.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"

unsigned int iterativeSumDigits(unsigned int number) {
	unsigned int acum = 0;
	while (number > 0) {
		acum += (number % 10);
		number /= 10;
	}
	return acum;
}

unsigned int recursiveSumDigits(unsigned int number) {
	if (number == 0) {
		return 0;
	} else {
		return (number % 10) + recursiveSumDigits(number / 10);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	cout << "iterativeSumDigits(123456): " << iterativeSumDigits(123456) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";

	crono.start();
	cout << "recursiveSumDigits(123456): " << recursiveSumDigits(123456) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";
	return 0;
}
