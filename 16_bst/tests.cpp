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
#include "bst.h"

TEST_CASE( "Testing BST implementation", "[BST]" ) {
	BST<int> bst;

	SECTION( "1: Testing if the bst is empty." ) {
		REQUIRE(bst.empty() == true);
	}

	SECTION( "2: Putting an element in the bst." ) {
		bst.add(5);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[5 ]") == 0);
		bst.add(1);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 5 ]") == 0);
		bst.add(10);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 5 10 ]") == 0);
		bst.add(3);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 3 5 10 ]") == 0);
		bst.add(7);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 3 5 7 10 ]") == 0);
	}

	SECTION( "3: Searching an element" ) {
		bst.add(5); bst.add(1); bst.add(10); bst.add(3); bst.add(7);
		REQUIRE(bst.find(7) == true);
		REQUIRE(bst.find(100) == false);
	}

	SECTION( "4: Removing an element" ) {
		bst.add(5); bst.add(1); bst.add(10); bst.add(3); bst.add(7);
		bst.remove(7);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 3 5 10 ]") == 0);
		bst.remove(5);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 3 10 ]") == 0);
		bst.remove(100);
		REQUIRE(strcmp(bst.inOrder().c_str(), "[1 3 10 ]") == 0);
	}

	SECTION( "6: Checking the preorder and postorder." ) {
		bst.add(5); bst.add(1); bst.add(10); bst.add(3); bst.add(7);
		REQUIRE(strcmp(bst.preOrder().c_str(), "[5 1 3 10 7 ]") == 0);
		REQUIRE(strcmp(bst.postOrder().c_str(), "[3 1 7 10 5 ]") == 0);
	}
}
