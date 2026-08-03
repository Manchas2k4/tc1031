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
#include "list.h"

/*
T    get(uint) const;

void insert_at(T, uint);

T    remove_at(uint);

long int  indexOf(T) const;
*/

TEST_CASE( "Testing list implementation", "[List]" ) {
	List<int> lst1, lst2, lst3;
	for (int i = 1; i <= 10; i++) {
		lst2.push_back(i);
		lst3.push_back(i);
	}

	SECTION( "1: Testing size of a list." ) {
		REQUIRE(lst1.length() == 0);
		REQUIRE(lst2.length() == 10);
	}

	SECTION( "2: Testing if list is empty." ) {
		REQUIRE(lst1.empty() == true);
		REQUIRE(lst2.empty() == false);
	}

	SECTION( "3: Testing if a element is in a list." ) {
		REQUIRE(lst2.contains(100) == false);
		REQUIRE(lst2.contains(5) == true);
	}

	SECTION( "4: Testing to clear a list." ) {
		lst3.clear();
		REQUIRE(lst3.length() == 0);
		REQUIRE(strcmp(lst3.toString().c_str(), "[]") == 0);
	}

	SECTION( "5: Getting the first element." ) {
		REQUIRE_THROWS_AS(lst1.front(), NoSuchElement);
		REQUIRE(lst2.front() == 1);
	}

	SECTION( "6: Getting the last element." ) {
		REQUIRE_THROWS_AS(lst1.last(), NoSuchElement);
		REQUIRE(lst2.last() == 10);
	}

	SECTION( "7: Pushing at the front." ) {
		lst1.push_front(0);
		REQUIRE(lst1.length() == 1);
		REQUIRE(strcmp(lst1.toString().c_str(), "[0]") == 0);

		lst2.push_front(0);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "8: Pushing at the back." ) {
		lst1.push_back(11);
		REQUIRE(lst1.length() == 1);
		REQUIRE(strcmp(lst1.toString().c_str(), "[11]") == 0);

		lst2.push_back(11);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);
	}

	SECTION( "9: Getting the front element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_front(), NoSuchElement);

		x = lst2.pop_front();
		REQUIRE(x == 1);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "10: Getting the last element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_back(), NoSuchElement);

		x = lst2.pop_back();
		REQUIRE(x == 10);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0);
	}
}
