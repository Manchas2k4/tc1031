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

// =================================================================
// Convert, iteratively, an integer to its binary representation
// (in strings).
//
// @param number, number to convert
// @return the string with the binary representation of the number.
// =================================================================
std::string iterativeDec2Bin(uint number) {
	std::string result = "";
	while (number > 0) {
		result = std::to_string(number % 2) + result;
		number /= 2;
	}
	return result;
}

// =================================================================
// Convert, recursively, an integer to its binary representation
// (in strings).
//
// @param number, number to convert
// @return the string with the binary representation of the number.
// =================================================================
std::string recursiveDec2Bin(uint number) {
	if (number == 1) {
		return std::to_string(number);
	} else {
		return recursiveDec2Bin(number / 2) + std::to_string(number % 2);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative dec2bin(1073741825): " << iterativeDec2Bin(1073741825) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive dec2bin(1073741825): " << recursiveDec2Bin(1073741825) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
