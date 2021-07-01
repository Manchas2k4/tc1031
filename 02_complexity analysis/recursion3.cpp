// =================================================================
//
// File: recursion03.cpp
// Author: Pedro Perez
// Description: This file contains the code that converts an integer
//				to a string in any base between 2 and 16.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstring>
#include "header.h"

const std::string convertString = std::string("0123456789ABCDEF");

// =================================================================
// Converts, recursively, a number in decimal base to any other
// base (maximum 16).
//
// @param n, the number to convert.
// @param base, the new base.
// @return a string with the number converted to the new base.
// =================================================================
std::string toString(uint n, uint base) {
	std::string result = "";
	if (n < base) {
		result += convertString[n];
	} else {
		result += toString(n / base, base) + convertString[n % base];
	}
	return result;
}

int main(int argc, char* argv[]) {
	uint number, base;

	std::cin >> number >> base;
	std::cout << toString(number, base) << "\n";
	return 0;
}
