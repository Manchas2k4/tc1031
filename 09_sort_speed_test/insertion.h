// =================================================================
//
// File: insertion.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				insertion sort. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#ifndef INSERTION_H
#define INSERTION_H

#include <iostream>
#include "header.h"

using namespace std;

template <class T>
void insertionSort(T *arr, int size) {
	for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
            swap(arr, j, j - 1);
        }
	}
}

#endif