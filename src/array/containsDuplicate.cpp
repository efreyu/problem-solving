//
// Created by Artur Barilo on 01.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <unordered_map>

class containsDuplicateTestSuite : public testing::Test {
public:
    // via hashtable
    bool containsDuplicateHash(std::vector<int>& nums) {
        std::unordered_map<int, bool> umap;
        for (auto& item : nums) {
            if (umap.count(item)) return true;
            umap[item] = true;
        }
        return false;
    }
    //via sorting and unique
    bool containsDuplicateUnique(std::vector<int>& nums) {
        std::sort(std::begin(nums), std::end(nums));
        auto it = std::unique(std::begin(nums), std::end(nums));
        return std::distance(std::begin(nums), it) != nums.size();
    }
};


TEST_F(containsDuplicateTestSuite, containsDuplicate) {
    std::vector<std::pair<std::vector<int>, bool>> cases = {
        { { 1,2,3,1 },  true},
        { { 1,2,3,4 }, false },
        { { 1,1,1,3,3,4,3,2,4,2 }, true }
    };

    for (auto& item : cases) {
        auto result = containsDuplicateHash(item.first);
        EXPECT_EQ(result, item.second);
        result = containsDuplicateUnique(item.first);
        EXPECT_EQ(result, item.second);
    }
}