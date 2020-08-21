// =================================================================
//
// File: recursion01.cpp
// Author: Pedro Perez
// Description: This file contains the code that takes a string 
//				(which represents an integer) as an argument and 
//				returns its value.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstring>

using namespace std;

int str2dec(const string &str, int n) {
	if (n == 1) {
		return str[0] - '0';
	} else {
		return ( (10 * str2dec(str, n - 1)) + (str[n - 1] - '0') );
	}
}

int main(int argc, char* argv[]) {
	string input;
	cin >> input;
	cout << str2dec(input, input.size()) << "\n";
	return 0;
}