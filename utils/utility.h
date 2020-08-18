#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while ( getline(tokenStream, token, delimiter) ) {
      tokens.push_back(token);
   }
   return tokens;
}

#endif