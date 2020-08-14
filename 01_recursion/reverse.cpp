// =================================================================
//
// File: factorial.cpp
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of the function that reverses a string.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include "header.h"

void iterativeReverse(string &s) {
	char aux;
	int i = 0;
	int j = s.size() - 1;

	while (i < j) {
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;

		i++;
		j--;
	}
}

void recursiveReverseAux(string &s, int i, int j) {
	char aux;

	if (i < j) {
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
		recursiveReverseAux(s, i + 1, j - 1);
	}
}

void recursiveReverse(string &s) {
	recursiveReverseAux(s, 0, s.size() - 1);
}

int main(int argc, char* argv[]) {
	string prueba("patito");

	iterativeReverse(prueba);
	cout << "patito: " << prueba << "\n";
	return 0;
}
