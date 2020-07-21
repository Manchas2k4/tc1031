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
#include "selection.h"

int output[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};

TEST(SelectionSortTest, WorstScenario)  { 
	int input[] = {94, 94, 93, 93, 92, 89, 82, 77, 76, 63, 56, 49, 45, 42, 30, 29, 24, 16, 2, 1};
	
	selectionSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}
 
TEST(SelectionSortTest, AverageScenario)  { 
	int input[] = {92, 1, 76, 89, 94, 30, 16, 24, 77, 93, 45, 56, 94, 93, 63, 29, 42, 82, 49, 2};
	
	selectionSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}

TEST(SelectionSortTest, BestScenario)  { 
	int input[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};
	
	selectionSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}
 
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}