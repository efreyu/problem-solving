//
// Created by Artur Barilo on 01.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <unordered_map>

class containsDuplicateTestSuite : public testing::Test {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, bool> map;
        for (auto& item : nums) {
            if (map.count(item)) return true;
            map[item] = true;
        }
        return false;
    }
};


TEST_F(containsDuplicateTestSuite, containsDuplicate) {
    std::vector<std::pair<std::vector<int>, bool>> cases = {
        { { 1,2,3,1 },  true},
        { { 1,2,3,4 }, false },
        { { 1,1,1,3,3,4,3,2,4,2 }, true }
    };

    for (auto& item : cases) {
        auto result = containsDuplicate(item.first);
        EXPECT_EQ(result, item.second);
    }
}