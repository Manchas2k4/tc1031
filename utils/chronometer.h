// =================================================================
//
// File: chronometer.h 
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the Chronometer class. This class is used to 
//				record the execution time of a program.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================

#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>

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

#endif
