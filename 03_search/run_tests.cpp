// =================================================================
//
// File: search.cpp 
// Author: Pedro Perez
// Description: This file implements various tests on the 
//				implemented code.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.  
// All Rights Reserved. May be reproduced for any non-commercial 
// purpose.
// =================================================================
#include <gtest/gtest.h>
#include "search.h"

int data[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};

TEST(SearchTest, SequentialSeach)  { 
	EXPECT_EQ(sequentialSearch(data, 20, 100), -1);
	EXPECT_EQ(sequentialSearch(data, 20, 1), 0);
}

TEST(SearchTest, BinarySearch)  { 
	EXPECT_EQ(binarySearch(data, 20, 100), -1);
	EXPECT_EQ(binarySearch(data, 20, 1), 0);
}
 
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}