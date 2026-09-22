// =================================================================
//
// File: run_test.cpp
// Author: Pedro Perez
// Description: This file implements various tests on the
//				implemented code.
//
// Copyright (c) 2026 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <stdexcept>
#include "catch.h"
#include "list.h"

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
		REQUIRE_THROWS_AS(lst1.front(), std::out_of_range);
		REQUIRE(lst2.front() == 1);
	}

	SECTION( "6: Getting the last element." ) {
		REQUIRE_THROWS_AS(lst1.last(), std::out_of_range);
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

		REQUIRE_THROWS_AS(lst1.pop_front(), std::out_of_range);

		x = lst2.front();
		lst2.pop_front();
		REQUIRE(x == 1);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "10: Getting the last element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_back(), std::out_of_range);

		x = lst2.last();
		lst2.pop_back();
		REQUIRE(x == 10);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0);
	}

	SECTION( "11: Testing get at a given index." ) {
		// empty list: any index is invalid
		REQUIRE_THROWS_AS(lst1.get(0), std::out_of_range);

		// first element
		REQUIRE(lst2.get(0) == 1);

		// middle element
		REQUIRE(lst2.get(4) == 5);

		// last element
		REQUIRE(lst2.get(9) == 10);

		// index == size (one past the end)
		REQUIRE_THROWS_AS(lst2.get(10), std::out_of_range);

		// index far out of range
		REQUIRE_THROWS_AS(lst2.get(100), std::out_of_range);
	}

	SECTION( "12: Testing insert_at at a given index." ) {
		// insert into an empty list at index 0
		lst1.insert_at(5, 0);
		REQUIRE(lst1.length() == 1);
		REQUIRE(strcmp(lst1.toString().c_str(), "[5]") == 0);

		// insert into an empty list at an invalid index (only index 0 is valid)
		List<int> lst4;
		REQUIRE_THROWS_AS(lst4.insert_at(9, 1), std::out_of_range);

		// insert at the front (index 0) of a non-empty list
		lst2.insert_at(0, 0);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);

		// insert at the end (index == size) of a non-empty list
		lst3.insert_at(11, 10);
		REQUIRE(lst3.length() == 11);
		REQUIRE(strcmp(lst3.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);

		// insert in the middle
		lst2.insert_at(100, 5);
		REQUIRE(lst2.length() == 12);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 100, 5, 6, 7, 8, 9, 10]") == 0);

		// insert out of range (index > size)
		REQUIRE_THROWS_AS(lst2.insert_at(999, 100), std::out_of_range);
	}

	SECTION( "13: Testing remove_at at a given index." ) {
		// removing from an empty list
		REQUIRE_THROWS_AS(lst1.remove_at(0), std::out_of_range);

		// remove the first element
		lst2.remove_at(0);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);

		// remove the last element
		lst3.remove_at(9);
		REQUIRE(lst3.length() == 9);
		REQUIRE(strcmp(lst3.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0);

		// remove a middle element
		lst2.remove_at(3);
		REQUIRE(lst2.length() == 8);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 6, 7, 8, 9, 10]") == 0);

		// out of range: index == size
		REQUIRE_THROWS_AS(lst2.remove_at(8), std::out_of_range);

		// out of range: index far beyond size
		REQUIRE_THROWS_AS(lst2.remove_at(100), std::out_of_range);

		// removing down to a single-element list, then to empty
		List<int> lst5;
		lst5.push_back(42);
		lst5.remove_at(0);
		REQUIRE(lst5.length() == 0);
		REQUIRE(lst5.empty() == true);
	}

	SECTION( "14: Testing indexOf a given value." ) {
		// value not found in an empty list
		REQUIRE(lst1.indexOf(5) == -1);

		// first element
		REQUIRE(lst2.indexOf(1) == 0);

		// middle element
		REQUIRE(lst2.indexOf(5) == 4);

		// last element
		REQUIRE(lst2.indexOf(10) == 9);

		// value not present
		REQUIRE(lst2.indexOf(999) == -1);

		// duplicate values: must return the FIRST occurrence
		lst2.push_back(5);
		REQUIRE(lst2.indexOf(5) == 4);
	}
}