//
// Created by Artur Barilo on 29.11.2021.
//
#include <gtest/gtest.h>
#include <vector>

class rotateArrayClass : public testing::Test {
public:
    void rotateArray(std::vector<int>& nums, int k) {
        k = k % nums.size();
//        std::vector<int> items(nums.end() - k, nums.end());
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.resize(nums.size() - k);
    }
};

struct sTest {
    std::vector<int> example;
    int k;
    std::vector<int> result;
    sTest(const std::vector<int>& _e, int _k, const std::vector<int>& _r) : example(_e), k(_k), result(_r) {}
};

TEST_F(rotateArrayClass, rotateArray) {
    std::vector<sTest> cases = {
        {{1,2,3}, 1, {3,1,2 }},
        {{1,2,3}, 4, {3,1,2 }},// 123 = 312 231 123 312
        {{1,2}, 3, {2,1}},//
        {{1,2}, 2, {1,2}},//
        {{1,2,3,4,5,6,7}, 3, {5,6,7,1,2,3,4}},
        {{1,2,3,4,5,6,7}, 1, {7,1,2,3,4,5,6}},
        {{1,2,3,4,5,6,7}, 2, {6,7,1,2,3,4,5}},

        {{-1,-100,3,99}, 2, {3,99,-1,-100}},
        {{-1,-100,3,99}, 1, {99,-1,-100,3}}
    };

    for (auto& item : cases) {
        rotateArray(item.example, item.k);
        EXPECT_EQ(item.example, item.result);
    }
}