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

using namespace std;

const string convertString = string("0123456789ABCDEF");

string toString(unsigned int n, unsigned int base) {
	string result = "";
	if (n < base) {
		result += convertString[n];
	} else {
		result += toString(n / base, base) + convertString[n % base];
	}
	return result;
}

int main(int argc, char* argv[]) {
	unsigned int number;
	unsigned int base;
	
	cin >> number >> base;
	cout << toString(number, base);
	return 0;
}