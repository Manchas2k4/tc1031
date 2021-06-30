// =================================================================
//
// File: tests.cpp
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
#include "search.h"

std::vector<int> data =
	{1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94};

TEST_CASE( "1: Searching a non existing number using sequential search",
           "[sequentialSearch]" ) {
	REQUIRE(sequentialSearch(data, 100) ==  -1);
}

TEST_CASE( "2: Searching a existing number using sequential search",
           "[sequentialSearch]" ) {
	REQUIRE(sequentialSearch(data, 16) ==  2);
}

TEST_CASE( "3: Searching a non existing number using non recursive binary search",
           "[binarySearch]" ) {
	REQUIRE(binarySearch(data, 100) ==  -1);
}

TEST_CASE( "4: Searching a existing number using non recursive binary search",
           "[binarySearch]" ) {
	REQUIRE(binarySearch(data, 16) ==  2);
}

TEST_CASE( "5: Searching a non existing number using recursive binary search",
           "[binaryRSearch]" ) {
	REQUIRE(binaryRSearch(data, 0, data.size() - 1, 100) ==  -1);
}

TEST_CASE( "6: Searching a existing number using recursive binary search",
           "[binaryRSearch]" ) {
	REQUIRE(binaryRSearch(data, 0, data.size() - 1, 16) ==  2);
}
