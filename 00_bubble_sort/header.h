// =================================================================
//
// File: header.h 
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the Chronometer class, as well as the 
//				implementation of some support functions. This class
//				is used to record the execution time of a program.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <string>

using namespace std;

class Chronometer {
private:
    timeval startTime;
    bool 	started;

public:
    Chronometer() :started(false) {}

    void start(){
    	started = true;
        gettimeofday(&startTime, NULL);
    }

    double stop(){
        timeval endTime;
        long seconds, useconds;
        double duration = -1;

        if (started) {
			gettimeofday(&endTime, NULL);

			seconds  = endTime.tv_sec  - startTime.tv_sec;
			useconds = endTime.tv_usec - startTime.tv_usec;

			duration = (seconds * 1000.0) + (useconds / 1000.0);
			started = false;
        }
		return duration;
    }
};

template <class T>
void swap(T *array, int i, int j) {
	T aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

template <class T>
void swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
string arr2str(T *array, int size) {
	stringstream aux;
	
	aux << "[" << array[0];
	for (int i = 1; i < size; i++) {
		aux << ", " << array[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
string vec2str(const std::vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

#endif