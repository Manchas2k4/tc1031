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
#include "catch.h"
#include "list.h"

TEST_CASE( "Testing list implementation", "[List]" ) {
	DoubleLinkedList<int> lst1, lst2;
	for (int i = 1; i <= 10; i++) {
		lst2.push_back(i);
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

	SECTION( "4: Getting the first element." ) {
		REQUIRE_THROWS_AS(lst1.front(), std::out_of_range);
		REQUIRE(lst2.front() == 1);
	}

	SECTION( "5: Getting the last element." ) {
		REQUIRE_THROWS_AS(lst1.last(), std::out_of_range);
		REQUIRE(lst2.last() == 10);
	}

	SECTION( "6: Pushing at the front." ) {
		lst1.push_front(0);
		REQUIRE(lst1.length() == 1);
		REQUIRE(strcmp(lst1.toString().c_str(), "[0]") == 0);

		lst2.push_front(0);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "7: Pushing at the back." ) {
		lst1.push_back(11);
		REQUIRE(lst1.length() == 1);
		REQUIRE(strcmp(lst1.toString().c_str(), "[11]") == 0);

		lst2.push_back(11);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);
	}

	SECTION( "8: Getting the front element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_front(), std::out_of_range);

		x = lst2.front();
		lst2.front();
		REQUIRE(x == 1);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
	}

	SECTION( "9: Getting the last element." ) {
		int x;

		REQUIRE_THROWS_AS(lst1.pop_back(), std::out_of_range);

		x = lst2.last();
		lst2.pop_back();
		REQUIRE(x == 10);
		REQUIRE(lst2.length() == 9);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0);
	}

	SECTION( "10: Testing before a given value." ) {
		// empty list
		REQUIRE_THROWS_AS(lst1.before(5), std::out_of_range);

		// value not found
		REQUIRE_THROWS_AS(lst2.before(999), std::out_of_range);

		// value is the first element: has nothing before it
		REQUIRE_THROWS_AS(lst2.before(1), std::out_of_range);

		// value in the middle
		REQUIRE(lst2.before(5) == 4);

		// value is the last element
		REQUIRE(lst2.before(10) == 9);

		// duplicate values: must use the FIRST occurrence
		lst2.push_back(5); // [1, 2, ..., 10, 5]
		REQUIRE(lst2.before(5) == 4);
	}

	SECTION( "11: Testing after a given value." ) {
		// empty list
		REQUIRE_THROWS_AS(lst1.after(5), std::out_of_range);

		// value not found
		REQUIRE_THROWS_AS(lst2.after(999), std::out_of_range);

		// value is the last element: has nothing after it
		REQUIRE_THROWS_AS(lst2.after(10), std::out_of_range);

		// value is the first element
		REQUIRE(lst2.after(1) == 2);

		// value in the middle
		REQUIRE(lst2.after(5) == 6);

		// duplicate values: must use the FIRST occurrence
		lst2.push_back(1); // [1, 2, ..., 10, 1]
		REQUIRE(lst2.after(1) == 2);
	}

	SECTION( "12: Testing insert_before a given value." ) {
		// empty list: lookingFor cannot be found
		REQUIRE_THROWS_AS(lst1.insert_before(1, 0), std::out_of_range);

		// lookingFor not found
		REQUIRE_THROWS_AS(lst2.insert_before(999, 0), std::out_of_range);

		// insert before the first element (new element becomes the head)
		lst2.insert_before(1, 0);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]") == 0);
		REQUIRE(lst2.front() == 0);

		// insert before a middle element
		lst2.insert_before(5, 100);
		REQUIRE(lst2.length() == 12);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 100, 5, 6, 7, 8, 9, 10]") == 0);

		// insert before the last element
		lst2.insert_before(10, 99);
		REQUIRE(lst2.length() == 13);
		REQUIRE(strcmp(lst2.toString().c_str(), "[0, 1, 2, 3, 4, 100, 5, 6, 7, 8, 9, 99, 10]") == 0);

		// verify bidirectional links after insertion
		REQUIRE(lst2.before(10) == 99);
		REQUIRE(lst2.after(99) == 10);
	}

	SECTION( "13: Testing insert_after a given value." ) {
		// empty list: lookingFor cannot be found
		REQUIRE_THROWS_AS(lst1.insert_after(1, 0), std::out_of_range);

		// lookingFor not found
		REQUIRE_THROWS_AS(lst2.insert_after(999, 0), std::out_of_range);

		// insert after the last element (new element becomes the last)
		lst2.insert_after(10, 11);
		REQUIRE(lst2.length() == 11);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);
		REQUIRE(lst2.last() == 11);

		// insert after the first element
		lst2.insert_after(1, 0);
		REQUIRE(lst2.length() == 12);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]") == 0);

		// insert after a middle element
		lst2.insert_after(5, 100);
		REQUIRE(lst2.length() == 13);
		REQUIRE(strcmp(lst2.toString().c_str(), "[1, 0, 2, 3, 4, 5, 100, 6, 7, 8, 9, 10, 11]") == 0);

		// verify bidirectional links after insertion
		REQUIRE(lst2.after(5) == 100);
		REQUIRE(lst2.before(100) == 5);
	}

	SECTION( "14: Testing push_front maintains bidirectional links." ) {
		lst1.push_front(5);
		lst1.push_front(4);
		lst1.push_front(3); // [3, 4, 5]

		REQUIRE(lst1.length() == 3);
		REQUIRE(strcmp(lst1.toString().c_str(), "[3, 4, 5]") == 0);
		REQUIRE(lst1.front() == 3);
		REQUIRE(lst1.last() == 5);

		REQUIRE(lst1.after(3) == 4);
		REQUIRE(lst1.after(4) == 5);
		REQUIRE(lst1.before(5) == 4);
		REQUIRE(lst1.before(4) == 3);
		REQUIRE_THROWS_AS(lst1.before(3), std::out_of_range);
		REQUIRE_THROWS_AS(lst1.after(5), std::out_of_range);
	}

	SECTION( "15: Testing push_back maintains bidirectional links." ) {
		lst1.push_back(3);
		lst1.push_back(4);
		lst1.push_back(5); // [3, 4, 5]

		REQUIRE(lst1.length() == 3);
		REQUIRE(strcmp(lst1.toString().c_str(), "[3, 4, 5]") == 0);
		REQUIRE(lst1.front() == 3);
		REQUIRE(lst1.last() == 5);

		REQUIRE(lst1.after(3) == 4);
		REQUIRE(lst1.after(4) == 5);
		REQUIRE(lst1.before(5) == 4);
		REQUIRE(lst1.before(4) == 3);
		REQUIRE_THROWS_AS(lst1.before(3), std::out_of_range);
		REQUIRE_THROWS_AS(lst1.after(5), std::out_of_range);
	}
}