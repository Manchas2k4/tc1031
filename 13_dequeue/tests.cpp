// =================================================================
//
// File: run_test.cpp
// Author: Pedro Perez
// Description: This file implements various tests on the
//				implemented code.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "dequeue.h"

TEST_CASE( "Testing dequeue implementation", "[Dequeue]" ) {
	Dequeue<int> dq1, dq2, dq3;
	for (int i = 1; i <= 10; i++) {
		dq2.push_back(i);
		dq3.push_back(i);
	}

	SECTION( "1: Testing size of a list." ) {
		REQUIRE(dq1.length() == 0);
		REQUIRE(dq2.length() == 10);
	}

	SECTION( "2: Testing if dequeue is empty." ) {
		REQUIRE(dq1.empty() == true);
		REQUIRE(dq2.empty() == false);
	}

	SECTION( "3: Testing if a element is in a list." ) {
		REQUIRE(dq2.contains(100) == false);
		REQUIRE(dq2.contains(5) == true);
	}

	SECTION( "4: Testing to clear a list." ) {
		dq3.clear();
		REQUIRE(dq3.length() == 0);
		REQUIRE(strcmp(dq3.toString().c_str(), "[]") == 0);
	}

	SECTION( "5: Getting the first element." ) {
		REQUIRE_THROWS_AS(dq1.front(), NoSuchElement);
		REQUIRE(dq2.front() == 1);
	}

	SECTION( "6: Getting the last element." ) {
		REQUIRE_THROWS_AS(dq1.last(), NoSuchElement);
		REQUIRE(dq2.last() == 10);
	}

	SECTION( "7: Pushing at the front." ) {
		dq1.push_front(0);
		REQUIRE(dq1.length() == 1);
		REQUIRE(strcmp(dq1.toString().c_str(), "[0]") == 0);

		dq2.push_front(0);
		REQUIRE(dq2.length() == 11);
		REQUIRE(strcmp(dq2.toString().c_str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "8: Pushing at the back." ) {
		dq1.push_back(11);
		REQUIRE(dq1.length() == 1);
		REQUIRE(strcmp(dq1.toString().c_str(), "[11]") == 0);

		dq2.push_back(11);
		REQUIRE(dq2.length() == 11);
		REQUIRE(strcmp(dq2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);
	}

	SECTION( "9: Getting the front element." ) {
		int x;

		REQUIRE_THROWS_AS(dq1.pop_front(), NoSuchElement);

		dq2.pop_front();
		REQUIRE(dq2.length() == 9);
		REQUIRE(strcmp(dq2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "10: Getting the last element." ) {
		int x;

		REQUIRE_THROWS_AS(dq1.pop_back(), NoSuchElement);

		dq2.pop_back();
		REQUIRE(dq2.length() == 9);
		REQUIRE(strcmp(dq2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0);
	}
}
