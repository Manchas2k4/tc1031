/*
 * unit.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef UNIT_H_
#define UNIT_H_

#include <iostream>
#include <cstdlib>

#define ASSERT_TRUE( condition ) assertTrue(condition,__FILE__,__LINE__,#condition);
#define ASSERT_FALSE( condition ) assertFalse(condition,__FILE__,__LINE__,#condition);
#define FAIL( error ) fail(__FILE__,__LINE__, error);

class UnitTest {
public:
	UnitTest();
	virtual ~UnitTest() = 0;

protected:
	void assertTrue(bool condition, const char*, int, const char*);
	void assertFalse(bool condition, const char*, int, const char*);
	void fail(const char*, int, const char*);
	static int num_test_sucess;
	static int total_test;
};

int UnitTest::num_test_sucess = 0;
int UnitTest::total_test = 1;

UnitTest::UnitTest() {}

UnitTest::~UnitTest() {}

void UnitTest::assertTrue(bool condition, const char *file, int line, const char *msg) {
	if (!condition) {
		std::cout << " FAILURE.\n";
		std::cout << file << ":" << line << ": " << msg << ", number of tests successful: " << num_test_sucess << " grade = " << ((num_test_sucess / (double) total_test) * 100) << " of 100\n";
		exit(1);
	}
	++num_test_sucess;
}

void UnitTest::assertFalse(bool condition, const char *file, int line, const char *msg) {
	if (condition) {
		std::cout << " FAILURE.\n";
		std::cout << file << ":" << line << ": " << msg << ", number of tests successful: " << num_test_sucess << "grade = " << ((num_test_sucess / (double) total_test) * 100) << " of 100\n";
		exit(1);
	}
	++num_test_sucess;
}

void UnitTest::fail(const char *file, int line, const char *msg) {
	std::cout << " FAILURE.\n";
	std::cout << file << ":" << line << ": " << msg << ", number of tests successful: " << num_test_sucess << "grade = " << ((num_test_sucess / (double) total_test) * 100) << " of 100\n";
	exit(1);
}

#endif /* UNIT_H_ */
