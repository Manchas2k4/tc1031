// =================================================================
//
// File: gcd.cpp
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of the gcd function. In mathematics,
//				the greatest common divisor (abbreviated GCD) of two
//				or more integers is defined to the largest integer
//				that divides them without leaving any remainder
//				(without over any number).
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"

unsigned int iterativeGCD(unsigned int a, unsigned int b) {
	unsigned int aux;
	while (b != 0) {
		aux = a;
		a = b;
		b = aux % b;
	}
	return a;
}

unsigned int recursiveGCD(unsigned int a, unsigned int b) {
	if (b == 0) {
		return a;
	} else {
		return recursiveGCD(b, a % b);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	cout << "iterative gcd(389, 271): " << iterativeGCD(389, 271) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";

	crono.start();
	cout << "recursive gcd(389, 271): " << recursiveGCD(389, 271) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n\n\n";

	crono.start();
	cout << "iterative gcd(97835033, 45083758): " << iterativeGCD(97835033, 45083758) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";

	crono.start();
	cout << "recursive gcd(97835033, 45083758): " << recursiveGCD(97835033, 45083758) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";
	return 0;
}
