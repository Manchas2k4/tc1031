// =================================================================
//
// File: binary.cpp
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of the function that converts a
//				decimal number to binary using recursion.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"

string iterativeDec2Bin(unsigned int number) {
	string result = "";
	while (number > 0) {
		result = to_string(number % 2) + result;
		number /= 2;
	}
	return result;
}

string recursiveDec2Bin(unsigned int number) {
	if (number == 1) {
		return to_string(number);
	} else {
		return recursiveDec2Bin(number / 2) + to_string(number % 2);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	cout << "iterative dec2bin(1073741825): " << iterativeDec2Bin(1073741825) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";

	crono.start();
	cout << "recursive dec2bin(1073741825): " << recursiveDec2Bin(1073741825) << "\n";
	ms = crono.stop();
	cout << "time: " << ms << " ms\n";
	return 0;
}
