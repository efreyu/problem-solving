//
// Created by Artur Barilo on 02.12.2021.
//
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class plusOneTestSuite : public testing::Test {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> result;
        int i = digits.size() - 1;
        int carry = (digits[i] + 1) / 10;
        int sum = (digits[i] + 1) % 10;
        result.push_back(sum);
        --i;
        while (i >= 0) {
            sum = (digits[i] + carry) % 10;
            result.push_back(sum);
            carry = (carry + (digits[i])) / 10;
            i--;
        }
        if (carry > 0)
            result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};


TEST_F(plusOneTestSuite, plusOne) {
    typedef std::pair<std::vector<int>, std::vector<int>> testCase;
    std::vector<testCase> cases = {
        { { 1, 2, 3 }, { 1, 2, 4 } },
        { { 4, 3, 2, 1 }, { 4, 3, 2, 2 } },
        { { 0 }, { 1 } },
        { { 9 }, { 1, 0 } },
        { { 9, 9 }, { 1, 0, 0 } }
    };

    for (auto& item : cases) {
        auto result = plusOne(item.first);
        EXPECT_EQ(result, item.second);
    }
}