#include <gtest/gtest.h>
#include "header.h"
#include "bubble.cpp"

unsigned grade = 0;
int output[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};

/*
void retro(const char* text, int cal) {
	grade += (::testing::Test::HasFailure())? 0 : cal;
	std::cout << text << " grade : " << grade << "\n";
}
*/
 
TEST(BubbleSortTest, WorstScenario)  { 
	int input[] = {94, 94, 93, 93, 92, 89, 82, 77, 76, 63, 56, 49, 45, 42, 30, 29, 24, 16, 2, 1};
	
	bubbleSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}
 
TEST(BubbleSortTest, AverageScenario)  { 
	int input[] = {92, 1, 76, 89, 94, 30, 16, 24, 77, 93, 45, 56, 94, 93, 63, 29, 42, 82, 49, 2};
	
	bubbleSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}

TEST(BubbleSortTest, BestScenario)  { 
	int input[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};
	
	bubbleSort(input, 20);
	EXPECT_STREQ(arr2str(input, 20).c_str(), arr2str(output, 20).c_str());
}
 
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}