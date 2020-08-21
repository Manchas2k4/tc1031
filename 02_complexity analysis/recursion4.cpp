// =================================================================
//
// File: recursion04.cpp
// Author: Pedro Perez
// Description: This file contains the code implements the solution 
//				to the mathematical problem known as Hanoi Tower
//				https://shorturl.at/fhjpw
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstring>

using namespace std;

void hanoi(int n, char start, char aux, char end) {
	if (n <= 0) {
		return;
	} else {
		hanoi(n - 1, start, end, aux);
		printf("Move disk %i, from %c to %c\n", n, start, end);
		hanoi(n - 1, aux, start, end);
	}
}

int main(int argc, char* argv[]) {
	unsigned int disks;
	
	cin >> disks;
	hanoi(disks, 'A', 'B', 'C');
	return 0;
}