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

TEST_CASE( "Testing circular list implementation", "[List]" ) {
	CircularList<int> lst1, lst2;
	for (int i = 1; i <= 10; i++) {
		lst2.push_back(i);
	}

	SECTION( "1: Testing if list is empty." ) {
		REQUIRE(lst1.empty() == true);
		REQUIRE(lst2.empty() == false);
	}

	SECTION( "2: Testing if a element is in a list." ) {
		REQUIRE(lst2.contains(100) == false);
		REQUIRE(lst2.contains(5) == true);
	}

	SECTION( "3: Pushing at the back." ) {
		lst1.push_back(11);
		REQUIRE(strcmp(lst1.toString().c_str(), "[11]") == 0);

		lst2.push_back(11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);
	}

	SECTION( "4: Getting the front element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_front(), NoSuchElement);

		x = lst2.pop_front();
		REQUIRE(x == 1);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}
}
