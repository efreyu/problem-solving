//
// Created by Artur Barilo on 27.07.2021.
//

#include <gtest/gtest.h>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class TestClass : public testing::Test {
};

TEST_F(TestClass, twoSum) {
	auto i = 0;
	auto a = 0;
	auto b = 1;

	EXPECT_EQ(i, a);
	EXPECT_TRUE(a != b);
}