//
// Created by Artur Barilo on 29.11.2021.
//
#include <gtest/gtest.h>
#include <vector>

class removeDuplicatesClass : public testing::Test {
public:
    int removeDuplicates(std::vector<int>& nums) {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

TEST_F(removeDuplicatesClass, removeDuplicates) {

    auto example1 = std::vector<int>({1, 1, 2});
    auto result1 = removeDuplicates(example1);
    auto expect1 = std::vector<int>({1, 2});
    EXPECT_EQ(example1, expect1);
    EXPECT_EQ(result1, 2);

    auto example2 = std::vector<int>({0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4});
    auto result2 = removeDuplicates(example2);
    auto expect2 = std::vector<int>({0, 1, 2, 3, 4});
    EXPECT_EQ(example2, expect2);
    EXPECT_EQ(result2, 5);

    auto example3 = std::vector<int>();
    auto result3 = removeDuplicates(example3);
    auto expect3 = std::vector<int>();
    EXPECT_EQ(example3, expect3);
    EXPECT_EQ(result3, 0);
}