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

// =================================================================
// Solve the Hanoi Towers problem.
//
// @param n, the number of discs.
// @param start, the initial pole.
// @param aux, the temporary pole.
// @param end, the end pole.
// =================================================================
void hanoi(int n, char start, char aux, char end) {
	if (n <= 0) {
		return;
	} else {
		hanoi(n - 1, start, end, aux);
		std::cout << "Move disk " << n << ", from " << start << " to "
							<< end << "\n";
		hanoi(n - 1, aux, start, end);
	}
}

int main(int argc, char* argv[]) {
	uint disks;

	std::cin >> disks;
	hanoi(disks, 'A', 'B', 'C');
	return 0;
}
