//
// Created by Artur Barilo on 01.12.2021.
//
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <algorithm>

class intersectionTestSuite : public testing::Test {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::set_intersection(nums1.begin(),nums1.end(), nums2.begin(),nums2.end(), back_inserter(result));
        return result;
    }
};


TEST_F(intersectionTestSuite, intersection) {
    typedef std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> testCase;
    std::vector<testCase> cases = {
        { {1,2,2,1}, {2,2}, {2,2}},
        { {4,9,5}, {4,9}, {4,9}}
    };

    for (auto& item : cases) {
        auto result = intersection(std::get<0>(item), std::get<1>(item));
        EXPECT_EQ(result, std::get<2>(item));
    }
}