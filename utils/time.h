// =================================================================
//
// File: time.h 
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the Time class. This class is used to record a 
//				time of day.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
//
// =================================================================

#ifndef TIME_H
#define TIME_H

#include <string>

using namespace std;

class Time {
private:
  int hours, minutes, seconds;

public:
  Time(const string &input) {
    string s(input);
    string delimiter = ":";

    hours = stoi(s.substr(0, s.find(delimiter)));
    s.erase(0, s.find(delimiter) + delimiter.length());

    minutes = stoi(s.substr(0, s.find(delimiter)));
    s.erase(0, s.find(delimiter) + delimiter.length());

    seconds = stoi(s.substr(0, s.find(delimiter)));
  }

  int getHours() const {
    return hours;
  }

  int getMinutes() const {
    return minutes;
  }

  int getSeconds() const {
    return seconds;
  }

  int toSeconds() const {
    return seconds + (minutes * 60) + (hours * 3600);
  }
};

bool operator< (const Time &a, const Time &b) {
  return a.toSeconds() < b.toSeconds();
}

#endif
