// =================================================================
//
// File: factorial.cpp
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of the factorial function. The
//				factorial of a positive integer n, the factorial of
//				n or n factorial is defined in principle as the
//				product of all positive integers from 1 (that is,
//				the natural numbers) to n.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"

// =================================================================
// Calculates, iteratively, the factorial of a number.
//
// @param number, number whose factorial is to be calculated.
// @return the factorial of a number
// =================================================================
lli iterativeFactorial(uint number) {
	lli acum = 1;
	for (uint i = 1; i <= number; i++) {
		acum *= i;
	}
	return acum;
}

// =================================================================
// Calculates, recursively, the factorial of a number.
//
// @param number, number whose factorial is to be calculated.
// @return the factorial of a number
// =================================================================
lli recursiveFactorial(uint number) {
	if (number == 0) {
		return 1;
	} else {
		return number * recursiveFactorial(number - 1);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative factorial(20): " << iterativeFactorial(20) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive factorial(20): " << recursiveFactorial(20) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
