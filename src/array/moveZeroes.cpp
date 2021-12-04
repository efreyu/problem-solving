//
// Created by Artur Barilo on 04.12.2021.
//
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class moveZeroesTestSuite : public testing::Test {
public:
    void moveZeroes(std::vector<int>& nums) {
        int countZeroes = 0;
        for (auto it = nums.begin(); it != nums.end(); ) {
            if ((*it) != 0) {
                ++it;
            } else {
                ++countZeroes;
                nums.erase(it);
            }
        }
        for (int i = 0; i < countZeroes; ++i) {
            nums.push_back(0);
        }
    }
};


TEST_F(moveZeroesTestSuite, moveZeroes) {
    typedef std::pair<std::vector<int>, std::vector<int>> testCase;
    std::vector<testCase> cases = {
        { {0,1,0,3,12 }, { 1,3,12,0,0 } },
        { { 0 }, { 0 } },
        { { 73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0 }, { 73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0 } }
    };

    for (auto& item : cases) {
        moveZeroes(item.first);
        EXPECT_EQ(item.first, item.second);
    }
}