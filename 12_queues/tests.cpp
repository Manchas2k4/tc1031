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
#include "queue.h"

TEST_CASE( "Testing vector implementation", "[QueueVector]" ) {
	QueueVector<int> q1(5), q2(5);
	for (int i = 0; i < 3; i++) {
		q2.enqueue(i);
	}

	SECTION( "1: Putting an element at the back." ) {
		q1.enqueue(0);
		REQUIRE(strcmp(q1.toString().c_str(), "[0]") == 0);
		q2.enqueue(3);
		REQUIRE(strcmp(q2.toString().c_str(), "[0, 1, 2, 3]") == 0);
	}

	SECTION( "2: Testing overflow." ) {
		q2.enqueue(3);
		q2.enqueue(4);
		REQUIRE_THROWS_AS(q2.enqueue(5), Overflow);
	}

	SECTION( "3: Checking the front" ) {
		REQUIRE_THROWS_AS(q1.front(), NoSuchElement);

		int x = q2.front();
		REQUIRE(x == 0);
		REQUIRE(strcmp(q2.toString().c_str(), "[0, 1, 2]") == 0);
	}

	SECTION( "4: Removing the front" ) {
		REQUIRE_THROWS_AS(q1.dequeue(), NoSuchElement);

		q2.dequeue();
		REQUIRE(strcmp(q2.toString().c_str(), "[1, 2]") == 0);
	}

	SECTION( "5: Testing if the queue is empty." ) {
		REQUIRE(q1.empty() == true);
		REQUIRE(q2.empty() == false);
	}

	SECTION( "6: Testing to clear a queue." ) {
		q2.clear();
		REQUIRE(strcmp(q2.toString().c_str(), "[]") == 0);
	}
}

TEST_CASE( "Testing list implementation", "[QueueList]" ) {
	QueueList<int> q1, q2;
	for (int i = 0; i < 3; i++) {
		q2.enqueue(i);
	}

	SECTION( "1: Putting an element at the back." ) {
		q1.enqueue(0);
		REQUIRE(strcmp(q1.toString().c_str(), "[0]") == 0);
		q2.enqueue(3);
		REQUIRE(strcmp(q2.toString().c_str(), "[0, 1, 2, 3]") == 0);
	}

	SECTION( "2: Checking the front" ) {
		REQUIRE_THROWS_AS(q1.front(), NoSuchElement);

		int x = q2.front();
		REQUIRE(x == 0);
		REQUIRE(strcmp(q2.toString().c_str(), "[0, 1, 2]") == 0);
	}

	SECTION( "3: Removing the front" ) {
		REQUIRE_THROWS_AS(q1.dequeue(), NoSuchElement);

		q2.dequeue();
		REQUIRE(strcmp(q2.toString().c_str(), "[1, 2]") == 0);
	}

	SECTION( "4: Testing if the queue is empty." ) {
		REQUIRE(q1.empty() == true);
		REQUIRE(q2.empty() == false);
	}

	SECTION( "5: Testing to clear a queue." ) {
		q2.clear();
		REQUIRE(strcmp(q2.toString().c_str(), "[]") == 0);
	}
}
