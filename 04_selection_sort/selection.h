// =================================================================
//
// File: selection.h
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				bubble sort. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include "header.h"

using namespace std;

// =================================================================
// Performs the selection sort algorithm.
// 
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
void selectionSort(T *arr, int size) {
	int pos;
	
	for(int i = size - 1; i > 0; i--){
        pos = 0;
        for(int j = 1; j <= i; j++){
            if(arr[j] > arr[pos]){
                pos = j;
            }
        }

        if (pos != i){
            swap(arr, i, pos);
        }
    }
}

#endif /* SELECTION_H */