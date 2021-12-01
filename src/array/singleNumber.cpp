//
// Created by Artur Barilo on 01.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <numeric>

class singleNumberTestSuite : public testing::Test {
public:
    int singleNumber(std::vector<int>& nums) {
        auto allSum = std::accumulate(nums.begin(), nums.end(), 0);
        std::sort(std::begin(nums), std::end(nums));
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        auto uniqueSum = std::accumulate(nums.begin(), nums.end(), 0);

        return 2 * uniqueSum - allSum;
    }
};


TEST_F(singleNumberTestSuite, singleNumber) {
    std::vector<std::pair<std::vector<int>, int>> cases = {
        { { 2,2,1 },  1},
        { { 4,1,2,1,2 }, 4 },
        { { 1 }, 1 }
    };

    for (auto& item : cases) {
        auto result = singleNumber(item.first);
        EXPECT_EQ(result, item.second);
    }
}