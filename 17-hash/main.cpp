/*
* main.cpp
*
*  Created on: 29/10/2015
*      Author: pperezm
*/

#include <iostream>
#include <cstring>
#include <string>
#include "unit.h"
#include "exception.h"
#include "hash.h"

using namespace std;

unsigned int myHash1(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

unsigned int myHash2(const string s) {
	return (unsigned int) s[0];
}

int main(int argc, char* argv[]) {
	HashTable<string, int> hash(10, string("empty"), myHash1);

	cout << hash.toString() << "\n\n";

	hash.put(string("tecnica"), 11);
	hash.put(string("casa"), 12);
	hash.put(string("caza"), 13);
	hash.put(string("amos"), 15);
	hash.put(string("magneto"), 17);
	hash.put(string("operador"), 18);
	hash.put(string("taza"), 18);
	cout << hash.toString() << "\n\n";

	hash.put(string("saca"), 10);
	cout << hash.toString() << "\n\n";

	hash.put(string("casa"), -10);
	cout << hash.toString() << "\n\n";

	return 0;
}
