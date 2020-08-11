// =================================================================
//
// File: vector.h 
// Author: Pedro Perez
// Description: This file contains the implementation of the 
//				Vector class
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================

#ifndef VECTOR_H
#define VECTOR_H

#include "exception.h"
#include <string>
#include <sstream>

template <class T>
class Vector {
private:
	unsigned int size;
	T	*data;

public:
	Vector(unsigned int);
	Vector(unsigned int, T);
	Vector(const Vector<T>&);
	~Vector();

	unsigned int length() const;
	unsigned int resize(unsigned int);
	std::string toString() const;

	T& operator[](unsigned int) const;
	void operator=(const Vector<T>&);
};

// =================================================================
// Constructor. Receives the initial size of the Vector.
// 
// @param numberOfElements initial size of the Vector.
// @throws when the location number is zero or there is not enough 
// 		   memory space for the vector.
// =================================================================
template <class T>
Vector<T>::Vector(unsigned int numberOfElements) {
    if(numberOfElements == 0){
        throw RangeError();
    }
    size = numberOfElements;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
}

// =================================================================
// Constructor. Receives the initial size of the Vector.
// 
// @param numberOfElements initial size of the Vector.
// @throws when the location number is zero or there is not enough 
// 		   memory space for the vector.
// =================================================================
template <class T>
Vector<T>::Vector(unsigned int numberOfElements, T initialValue) {
    if(numberOfElements == 0){
        throw RangeError();
    }
    size = numberOfElements;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
	
	for (unsigned int i = 0; i < size; i++) {
		data[i] = initialValue;
	}
}

// =================================================================
// Copy constructor. It will create a copy of the source Vector.
// 
// @param source the Vector of which it will create a copy.
// @throws when there is not enough memory space.
// =================================================================
template <class T>
Vector<T>::Vector(const Vector<T> &source) {
    size = source.size;
    data = new T[size];
    if(data == 0){
        throw OutOfMemory();
    }
    for(unsigned int i = 0; i < size; i++){
        data[i] = source.data[i];
    }
}


// =================================================================
// Destructor. Free the memory space used by the class.
// =================================================================
template <class T>
Vector<T>::~Vector() {
    delete [] data;
    data = 0;
    size = 0;
}

// =================================================================
// Return the size of the Vector.
// =================================================================
template <class T>
unsigned int Vector<T>::length() const {
	return size;
}

// =================================================================
// Resize the Vector. If thew new size is less than the original 
// size, only copy the first element. Otherwise, copy all the values.
// 
// @param newSize the new size of the Vector.
// @return the new Vector size.
// @throws when there is not enough memory space.
// =================================================================
template <class T>
unsigned int Vector<T>::resize(unsigned int newSize) {
	if (newSize == 0){
		throw RangeError();
	}
	
	if (size == newSize) {
		return size;
	}

	T *newData = new T[newSize];
	if(newData == 0){
		throw OutOfMemory();
	}

	if(newSize < size){
		for(unsigned int i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	} else{
		for(unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
	}

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

// =================================================================
// Return the string representation of the Vector.
// 
// @return a string representation.
// =================================================================
template <class T>
std::string Vector<T>::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (unsigned int i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Overload the operator [] to operate with the Vector class.
// 
// @param index a valid position of the Vector.
// @return the value, by reference, which is in the position 
//		   indicated by index.
// @throws when the index is invalid.
// =================================================================
template <class T>
T& Vector<T>::operator[] (unsigned int index) const {
    if(index >= size){
        throw IndexOutOfBounds();
    }
	return data[index];
}

// =================================================================
// Overload the assignment operator. Make an identical copy of the 
// source Vector.
// 
// @param source the Vector to be copied
// =================================================================
template <class T>
void Vector<T>::operator=(const Vector<T> &right) {
    if(size != right.size){
        resize(right.size);
    }
    for(unsigned int i =0; i < right.size; i++){
        data[i] = right.data[i];
    }
}

#endif /* VECTOR_H */
