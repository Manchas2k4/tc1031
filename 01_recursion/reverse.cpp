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

// =================================================================
// Invert, iteratively, a string.
//
// @param s, the string to reverse.
// =================================================================
void iterativeReverse(std::string &s) {
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

// =================================================================
// Invert, recursively, a string.
//
// @param s, the string to reverse.
// @param i, the lower limit.
// @param j, the upper limit.
// =================================================================
void recursiveReverseAux(std::string &s, int i, int j) {
	char aux;

	if (i < j) {
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
		recursiveReverseAux(s, i + 1, j - 1);
	}
}

void recursiveReverse(std::string &s) {
	recursiveReverseAux(s, 0, s.size() - 1);
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;
	std::string prueba1("En el caso de querer firmar (propiedades de autenticidad, integridad y no repudio), el emisor obtiene un hash del mensaje a firmar y lo");
	std::string prueba2("En el caso de querer firmar (propiedades de autenticidad, integridad y no repudio), el emisor obtiene un hash del mensaje a firmar y lo");
	
	crono.start();
	iterativeReverse(prueba1);
	std::cout << "iterative reverse(prueba): " << prueba1 << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	
	crono.start();
	recursiveReverse(prueba2);
	std::cout << "recursive reverse(prueba): " << prueba2 << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	return 0;
}
