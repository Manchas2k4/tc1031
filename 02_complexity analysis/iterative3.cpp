// =================================================================
//
// File: iterative.cpp
// Author: Pedro Perez
// Description: This file implements the solution for problem 664a 
//				of Codeforces site. The complete description of the 
//				problem can be found in the following link:
//				https://codeforces.com/problemset/problem/664/A
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	string a, b;
	
	cin >> a >> b;
	if (a == b) {
		cout << a << "\n";
	} else {
		cout << "1\n";
	}
	return 0;
}