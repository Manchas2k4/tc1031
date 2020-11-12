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

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

unsigned int myHash(const string s) {
	return (unsigned int) s[0];
}

class HashTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 11;

		/* TEST 1 */
		cout << "Test 1..." <<  hash.toString().c_str() << "\n";
		HashTable<string, int> hash(10, string("empty"), myHash);
		ASSERT_TRUE(!strcmp("[ 0, empty, 0]\n[ 1, empty, 0]\n[ 2, empty, 0]\n[ 3, empty, 0]\n[ 4, empty, 0]\n[ 5, empty, 0]\n[ 6, empty, 0]\n[ 7, empty, 0]\n[ 8, empty, 0]\n[ 9, empty, 0]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 2...";

		/* TEST 2 */
		hash.put(string("tecnica"), 11);
		hash.put(string("casa"), 12);
		hash.put(string("caza"), 13);
		hash.put(string("amos"), 15);
		hash.put(string("magneto"), 17);
		hash.put(string("operador"), 18);
		hash.put(string("taza"), 18);
		ASSERT_TRUE(!strcmp("[ 0, operador, 18]\n[ 1, empty, 0]\n[ 2, amos, 15]\n[ 3, taza, 18]\n[ 4, empty, 0]\n[ 5, caza, 13]\n[ 6, empty, 0]\n[ 7, tecnica, 11]\n[ 8, casa, 12]\n[ 9, magneto, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 3...";

		/* TEST 3 */
		hash.put(string("amor"), 10);
		ASSERT_TRUE(!strcmp("[ 0, operador, 18]\n[ 1, amor, 10]\n[ 2, amos, 15]\n[ 3, taza, 18]\n[ 4, empty, 0]\n[ 5, caza, 13]\n[ 6, empty, 0]\n[ 7, tecnica, 11]\n[ 8, casa, 12]\n[ 9, magneto, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 4...";

		/* TEST 4 */
		hash.put(string("roma"), 16);
		ASSERT_TRUE(!strcmp("[ 0, operador, 18]\n[ 1, amor, 10]\n[ 2, amos, 15]\n[ 3, taza, 18]\n[ 4, roma, 16]\n[ 5, caza, 13]\n[ 6, empty, 0]\n[ 7, tecnica, 11]\n[ 8, casa, 12]\n[ 9, magneto, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 5...";

		/* TEST 5 */
		hash.put(string("mora"), 18);
		ASSERT_TRUE(!strcmp("[ 0, operador, 18]\n[ 1, amor, 10]\n[ 2, amos, 15]\n[ 3, taza, 18]\n[ 4, roma, 16]\n[ 5, caza, 13]\n[ 6, mora, 18]\n[ 7, tecnica, 11]\n[ 8, casa, 12]\n[ 9, magneto, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 6...";

		/* TEST 6 */
		try {
			hash.put(string("murcielago"), 100);
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("Overflow", e.what()));
			std::cout << " PASSED.\nTest 7...";
		}

		/* TEST 7 */
		hash.put(string("operador"), 1111);
		ASSERT_TRUE(!strcmp("[ 0, operador, 1111]\n[ 1, amor, 10]\n[ 2, amos, 15]\n[ 3, taza, 18]\n[ 4, roma, 16]\n[ 5, caza, 13]\n[ 6, mora, 18]\n[ 7, tecnica, 11]\n[ 8, casa, 12]\n[ 9, magneto, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\nTest 8...";

		/* TEST 8 */
		ASSERT_TRUE(1 == hash.contains(string("operador")));
		ASSERT_TRUE(0 == hash.contains(string("murcielago")));
		std::cout << " PASSED.\nTest 9...";

		/* TEST 9 */
		ASSERT_TRUE(15 == hash.get(string("amos")));
		std::cout << " PASSED.\nTest 10...";

		/* TEST 10 */
		try {
			hash.get(string("murcielago"));
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 11...";
		}

		/* TEST 11 */
		hash.clear();
		ASSERT_TRUE(!strcmp("[ 0, empty, 1111]\n[ 1, empty, 10]\n[ 2, empty, 15]\n[ 3, empty, 18]\n[ 4, empty, 16]\n[ 5, empty, 13]\n[ 6, empty, 18]\n[ 7, empty, 11]\n[ 8, empty, 12]\n[ 9, empty, 17]\n", hash.toString().c_str()));
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	HashTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}
