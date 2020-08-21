// =================================================================
//
// File: bubble.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				bubble sort. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
#include "header.h"

using namespace std;

template <class T>
void bubbleSort(T *arr, int size) {
	for(int i = size - 1; i > 0; i--){
		for(int j = 0;  j < i; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr, j, j + 1);
			}
		}
	}
}

#endif