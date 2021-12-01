//
// Created by Artur Barilo on 01.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

class maxProfitTestSuite : public testing::Test {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += std::max(prices[i] - prices[i-1], 0);
        }
        return profit;
    }
};


TEST_F(maxProfitTestSuite, maxProfit) {
    std::vector<std::pair<std::vector<int>, int>> cases = {
        { { 7, 1, 5, 3, 6, 4 },  7},
        { { 1, 2, 3, 4, 5 }, 4 },
        { { 7, 6, 4, 3, 1 }, 0 }
    };

    for (auto& item : cases) {
        auto result = maxProfit(item.first);
        EXPECT_EQ(result, item.second);
    }
}