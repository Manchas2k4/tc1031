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
#include <gtest/gtest.h>
#include "vector.h"

/*
class VectorTest : public ::testing::Test {
	
protected:
	void SetUp() override {
	}
	
	void TearDown() override {
		
	}
};
*/

TEST(VectorTest, SizeZeroTest) { 
	try {
		Vector<int>(0);
		FAIL() << "RangeError not thrown";
	} catch (std::exception &e) {
		EXPECT_STREQ(e.what(), "RangeError");
	} 
	try {
		Vector<int>(0, 10);
		FAIL() << "RangeError not thrown";
	} catch (std::exception &e) {
		EXPECT_STREQ(e.what(), "RangeError");
	} 
}

TEST(VectorTest, InitWithValue)  {
	Vector<int> v1(5, 1);
	EXPECT_EQ(v1.length(), 5);
	EXPECT_STREQ(v1.toString().c_str(), "[1, 1, 1, 1, 1]");
}

TEST(VectorTest, CopyConstructor)  {
	Vector<int> v1(5, 1);
	Vector<int> v2(v1);
	EXPECT_EQ(v2.length(), 5);
	EXPECT_STREQ(v2.toString().c_str(), "[1, 1, 1, 1, 1]");
}

TEST(VectorTest, ResizeToZero)  {
	Vector<int> v1(10, 1);
	try {
		v1.resize(0);
		FAIL() << "RangeError not thrown";
	} catch (std::exception &e) {
		EXPECT_STREQ(e.what(), "RangeError");
	} 
}

TEST(VectorTest, IncreaseSize)  {
	Vector<int> v1(10, 1);
	v1.resize(15);
	EXPECT_EQ(v1.length(), 15);
}

TEST(VectorTest, ReduceSize)  {
	Vector<int> v1(10, 1);
	v1.resize(5);
	EXPECT_EQ(v1.length(), 5);
	EXPECT_STREQ(v1.toString().c_str(), "[1, 1, 1, 1, 1]");
}

TEST(VectorTest, InvalidIndex)  {
	Vector<int> v1(10, 1);
	int val;
	
	try {
		val = v1[100];
		FAIL() << "IndexOutOfBounds not thrown";
	} catch (std::exception &e) {
		EXPECT_STREQ(e.what(), "IndexOutOfBounds");
	} 
}

TEST(VectorTest, ChangingValue)  {
	Vector<int> v1(10, 1);
	v1[1] = 2;
	EXPECT_EQ(v1[1], 2);
}

TEST(VectorTest, AssignmentOperator)  {
	Vector<int> v1(10, 1);
	Vector<int> v2(5, 2);
	
	EXPECT_EQ(v2.length(), 5);
	EXPECT_STREQ(v2.toString().c_str(), "[2, 2, 2, 2, 2]");
	v2 = v1;
	EXPECT_EQ(v2.length(), 10);
	EXPECT_STREQ(v2.toString().c_str(), "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]");
}
 
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}