//
// Created by Artur Barilo on 02.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

class plusOneTestSuite : public testing::Test {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        auto& it = digits.back();
        if (it < 9) {
            ++it;
            return digits;
        }
        it = 1;
        digits.push_back(0);
        return digits;
    }
};


TEST_F(plusOneTestSuite, plusOne) {
    typedef std::pair<std::vector<int>, std::vector<int>> testCase;
    std::vector<testCase> cases = {
        { {1,2,3}, {1,2,4}},
        { {4,3,2,1}, {4,3,2,2}},
        { {0}, {1}},
        { {9}, {1,0}}
    };

    for (auto& item : cases) {
        auto result = plusOne(item.first);
        EXPECT_EQ(result, item.second);
    }
}