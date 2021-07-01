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
#include "stack.h"

TEST_CASE( "Testing vector implementation", "[StackVector]" ) {
	StackVector<int> s1(5), s2(5);
	for (int i = 0; i < 3; i++) {
		s2.push(i);
	}

	SECTION( "1: Pushing an element at the top." ) {
		s1.push(0);
		REQUIRE(strcmp(s1.toString().c_str(), "[0]") == 0);
		s2.push(3);
		REQUIRE(strcmp(s2.toString().c_str(), "[0, 1, 2, 3]") == 0);
	}

	SECTION( "2: Testing overflow." ) {
		s2.push(3);
		s2.push(4);
		REQUIRE_THROWS_AS(s2.push(5), Overflow);
	}

	SECTION( "3: Checking the top" ) {
		REQUIRE_THROWS_AS(s1.pop(), NoSuchElement);

		int x = s2.top();
		REQUIRE(x == 2);
		REQUIRE(strcmp(s2.toString().c_str(), "[0, 1, 2]") == 0);
	}

	SECTION( "4: Popping out the top" ) {
		REQUIRE_THROWS_AS(s1.pop(), NoSuchElement);

		s2.pop();
		REQUIRE(strcmp(s2.toString().c_str(), "[0, 1]") == 0);
	}

	SECTION( "5: Testing if the stack is empty." ) {
		REQUIRE(s1.empty() == true);
		REQUIRE(s2.empty() == false);
	}

	SECTION( "6: Testing to clear a stack." ) {
		s2.clear();
		REQUIRE(strcmp(s2.toString().c_str(), "[]") == 0);
	}
}

TEST_CASE( "Testing list implementation", "[StackList]" ) {
	StackList<int> s1, s2;
	for (int i = 0; i < 3; i++) {
		s2.push(i);
	}

	SECTION( "1: Pushing an element at the top." ) {
		s1.push(0);
		REQUIRE(strcmp(s1.toString().c_str(), "[0]") == 0);
		s2.push(3);
		REQUIRE(strcmp(s2.toString().c_str(), "[3, 2, 1, 0]") == 0);
	}

	SECTION( "2: Checking the top" ) {
		REQUIRE_THROWS_AS(s1.pop(), NoSuchElement);

		int x = s2.top();
		REQUIRE(x == 2);
		std::cout << s2.toString() << "\n";
		REQUIRE(strcmp(s2.toString().c_str(), "[2, 1, 0]") == 0);
	}

	SECTION( "4: Popping out the top" ) {
		REQUIRE_THROWS_AS(s1.pop(), NoSuchElement);

		s2.pop();
		REQUIRE(strcmp(s2.toString().c_str(), "[1, 0]") == 0);
	}

	SECTION( "5: Testing if the stack is empty." ) {
		REQUIRE(s1.empty() == true);
		REQUIRE(s2.empty() == false);
	}

	SECTION( "6: Testing to clear a stack." ) {
		s2.clear();
		REQUIRE(strcmp(s2.toString().c_str(), "[]") == 0);
	}
}
