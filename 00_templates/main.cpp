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
#include "vector.h"

TEST_CASE( "1: Create a vector with size = 0", "[Vector(uint)]" ) {
	REQUIRE_THROWS_AS(Vector<int>(0), RangeError);
}


TEST_CASE( "2: Create a vector with size = 0", "[Vector(uint, int)]" ) {
	REQUIRE_THROWS_AS(Vector<int>(0, 10), RangeError);
}

TEST_CASE( "3: Create a copy of a vector", "[Vector(const Vector<T>&)]" ) {
	Vector<int> v1(5, 1);
	Vector<int> v2(v1);
	REQUIRE(v1.length() == v2.length());
	REQUIRE(strcmp(v1.toString().c_str(), v2.toString().c_str()) == 0);
}

TEST_CASE( "4: Checking the initial value of a vector", "[Vector(uint, int)]" ) {
	Vector<int> v1(5, 1);
	REQUIRE(v1.length() == 5);
	REQUIRE(strcmp(v1.toString().c_str(), "[1, 1, 1, 1, 1]") == 0);
}

TEST_CASE( "5: Resize to size = 1", "[resize(uint)]" ) {
	Vector<int> v1(10, 1);
	REQUIRE_THROWS_AS(v1.resize(0), RangeError);
}

TEST_CASE( "6: Increasing size", "[resize(uint)]" ) {
	Vector<int> v1(10, 1);
	v1.resize(15);
	REQUIRE(v1.length() == 15);
}

TEST_CASE( "7: Decreasing size", "[resize(uint)]" ) {
	Vector<int> v1(10, 1);
	v1.resize(5);
	REQUIRE(v1.length() == 5);
	REQUIRE(strcmp(v1.toString().c_str(), "[1, 1, 1, 1, 1]") == 0);
}

TEST_CASE( "8: Index out of bounds", "[operator[]]" ) {
	Vector<int> v1(10, 1);
	int val;

	REQUIRE_THROWS_AS(v1[100], IndexOutOfBounds);
}

TEST_CASE( "9: Changing value at position x", "[operator[]]" ) {
	Vector<int> v1(10, 1);
	v1[1] = 2;
	REQUIRE(v1[1] == 2);
}

TEST_CASE( "10: Copying a vector to another one", "[operator=" ) {
	Vector<int> v1(10, 1);
	Vector<int> v2(5, 2);

	CHECK(v2.length() == 5);
	CHECK(strcmp(v2.toString().c_str(), "[2, 2, 2, 2, 2]") == 0);
	v2 = v1;
	REQUIRE(v2.length() == 10);
	REQUIRE(strcmp(v2.toString().c_str(), "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]") == 0);
}
