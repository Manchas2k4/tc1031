#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while ( getline(tokenStream, token, delimiter) ) {
      tokens.push_back(token);
   }
   return tokens;
}

vector<string> split(const string &s, char delimiter, int amount) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   int i;

   i = 1;
   while ( i <= amount && getline(tokenStream, token, delimiter) ) {
      tokens.push_back(token);
      i++;
   }
   cout << "----" << tokenStream.str() << "\n";
   return tokens;
}
#endif
