// =================================================================
//
// File: ip_address.h 
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the IpAddress class. 
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
//
// =================================================================

#ifndef IP_ADDRESS_H
#define IP_ADDRESS_H

#include <string>

using namespace std;

class IpAddress {
private:
  string ip;
  int port;

public:
  IpAddress(const string &input) {
    string s(input);
    string delimiter = ":";

    ip = s.substr(0, s.find(delimiter));
    s.erase(0, s.find(delimiter) + delimiter.length());

    port = stoi(s.substr(0, s.find(delimiter)));
  }

  string getIP() const {
    return ip;
  }

  int getPort() const {
    return port;
  }
};

#endif
