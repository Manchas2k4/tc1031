// =================================================================
//
// File: record.h
// Author: Pedro Perez
// Description: This file contains the implementation of Record
//              class.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef RECORD_H
#define RECORD_H

#include "header.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Record {
private:
  int day;
  int month;
  string monthName;
  string hour;
  string ip;
  string message;

  int month2Number(string);

public:
    Record();
    Record(string, string);
    Record(string, string, string, string, string);
    Record(const Record &);
    int getMonth() const;
    int getDay() const;
    string toString() const;
};

Record::Record()
  : day(1), monthName(string("Jan")), month(1), hour(string("0:0:0")),
    ip(string("127.0.0.1:0001")), message(string("empty")) {
}

Record::Record(string m, string d) {
  day = stoi(d);
  monthName = m;
  month = month2Number(monthName);
  hour = string("0:0:0");
  ip = string("127.0.0.1:0001");
  message = string("empty");
}

Record::Record(string m, string d, string h, string i, string msg) {
  day = stoi(d);
  monthName = m;
  month = month2Number(monthName);
  hour = h;
  ip = i;
  message = msg;
}

Record::Record(const Record &r)
  : day(r.day), monthName(r.monthName), month(r.month), hour(r.hour),
    ip(r.ip), message(r.message) {
}

int Record::getMonth() const {
  return month;
}

int Record::getDay() const {
  return day;
}

int Record::month2Number(string s) {
  if (s == "Jan") return 1;
  else if (s == "Feb") return 2;
  else if (s == "Mar") return 3;
  else if (s == "Apr") return 4;
  else if (s == "May") return 5;
  else if (s == "Jun") return 6;
  else if (s == "Jul") return 7;
  else if (s == "Aug") return 8;
  else if (s == "Sep") return 9;
  else if (s == "Oct") return 10;
  else if (s == "Nov") return 11;
  else return 12;
}

string Record::toString() const {
  stringstream aux;

  aux << monthName << " " << day << " " << hour << " " << ip << " " << message;
  return aux.str();
}

bool operator==(const Record &a, const Record &b) {
  return ( (a.getMonth() == b.getMonth()) &&
           (a.getDay() == b.getDay()) );
}

bool operator<(const Record &a, const Record &b) {
  if (a.getMonth() == b.getMonth()) {
    return (a.getDay() < b.getDay());
  } else {
    return (a.getMonth() < b.getMonth());
  }
}

bool operator>(const Record &a, const Record &b) {
  if (a.getMonth() == b.getMonth()) {
    return (a.getDay() > b.getDay());
  } else {
    return (a.getMonth() > b.getMonth());
  }
}

/*
bool operator>=(const Record &a, const Record &b) {
  if (a.getMonth() == b.getMonth()) {
    return (a.getDay() >= b.getDay());
  } else {
    return (a.getMonth() >= b.getMonth());
  }
}
*/
#endif
