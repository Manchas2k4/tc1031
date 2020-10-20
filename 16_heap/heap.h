/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"

typedef unsigned int uint;

template <class T>
class Heap {
private:
	T *data;
	uint size;
	uint count;

	uint parent(uint) const;
	uint left(uint) const;
	uint right(uint) const;
	void pushDown(uint);
	void swap(uint, uint);

public:
	Heap(uint);
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T);
	T remove();
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(uint sze) {
    size = sze;
    data = new T[size];
    count = 0;
}

template <class T>
Heap<T>::~Heap() {
    delete [] data;
    data = 0;
    size = 0;
    count = 0;
}

template <class T>
bool Heap<T>::empty() const {
    return (count == 0);
}

template <class T>
bool Heap<T>::full() const {
	return (count == size);
}

template <class T>
uint Heap<T>::parent(uint pos) const {
	return (pos - 1) / 2;
}

template <class T>
uint Heap<T>::left(uint pos) const {
	return (pos * 2) + 1;
}

template <class T>
uint Heap<T>::right(uint pos) const {
	return (pos * 2) + 2;
}

template <class T>
void Heap<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::pushDown(uint pos) {
    uint le = left(pos);
    uint ri = right(pos);
    uint min = pos;

    if (le < count && data[le] < data[min]){
        min = le;
    }
    if (ri < count && data[ri] < data[min]){
        min = ri;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}

template <class T>
void Heap<T>::add(T val) {
    uint pos;
    if (full()){
        throw Overflow();
    }

    pos = count;
    count++;
    while(pos > 0 && val < data[parent(pos)]){
        data[pos]= data[parent(pos)];
        pos = parent(pos);
    }
    data[pos] = val;
}

template <class T>
T Heap<T>::remove() {
	if (empty()){
		throw NoSuchElement();
	}

	T aux = data[0];
	data[0] = data[--count];
	pushDown(0);
	return aux;
}

template <class T>
void Heap<T>::clear() {
    count = 0;
}


template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H */
