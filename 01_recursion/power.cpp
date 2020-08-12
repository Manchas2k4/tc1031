// =================================================================
//
// File: factorial.cpp 
// Author: Pedro Perez
// Description: This file contains the implementation iterative and
//				and recursive of a function of x raised to the nth 
//				power.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#include "header.h"

double fast_pow(double x, int n) {
	if (n < 0) {
		return fast_pow(1/x, -n);
	} else if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		return fast_pow(x * x, n / 2);
	} else if (n % 2 != 0) {
		return x * fast_pow(x * x, (n - 1) / 2);
	}
}

int main(int argc, char* argv[]) {
	return 0;
}
