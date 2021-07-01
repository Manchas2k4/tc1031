// =================================================================
//
// File: iterative.cpp
// Author: Pedro Perez
// Description: This file implements the solution for problem 699b
//				of Codeforces site. The complete description of the
//				problem can be found in the following link:
//				https://codeforces.com/problemset/problem/699/b
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
	int n, m, i, j, col, row;
	bool possible;
	char c;

	scanf("%i %i", &n, &m);

	row = col = -1;
	possible = true;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%c", &c);
			if (c == '*') {
				if (row != -1) {
					if (row != i) {
						possible = false;
					}
				} else {
					row = i;
				}

				if (col != -1) {
					if (col != j) {
						possible = false;
					}
				} else {
					col = j;
				}
			}
		}
	}
	if (!possible) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::cout << (row + 1) << " " << (col + 1) << "\n";
	}
	return 0;
}
