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

long long int iterativeFactorial(unsigned int number) {
	long long int acum = 1;
	for (unsigned int i = 1; i <= number; i++) {
		acum *= i;
	}
	return acum;
}

long long int recursiveFactorial(unsigned int number) {
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
	cout << "iterative factorial(20): " << iterativeFactorial(20) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";
	
	crono.start();
	cout << "recursive factorial(20): " << recursiveFactorial(20) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";
	return 0;
}