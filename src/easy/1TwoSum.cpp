//
// Created by Artur Barilo on 27.07.2021.
//

#include <gtest/gtest.h>
#include <vector>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class solutionClass : public testing::Test {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		auto vec = std::vector<int>();
		for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
			if (vec.empty() && nums[i] < target) {
				vec.push_back(i);
			} else {
				for (auto key : vec) {
					if (nums[static_cast<size_t>(key)] + nums[i] == target) {
						return std::vector<int>({key, i});
					}
				}
				vec.push_back(i);
			}
		}

		return std::vector<int>();

	}
};

TEST_F(solutionClass, twoSum) {

	auto example1 = std::vector<int>({2, 7, 11, 15});
	auto result1 = twoSum(example1, 9);
	auto expect1 = std::vector<int>({0, 1});
	EXPECT_EQ(twoSum(example1, 9), std::vector<int>({0, 1}));

	auto example2 = std::vector<int>({3, 2, 4});
	auto result2 = twoSum(example2, 6);
	auto expect2 = std::vector<int>({1, 2});
	EXPECT_EQ(twoSum(example2, 6), std::vector<int>({1, 2}));

	auto example3 = std::vector<int>({3, 2, 4});
	auto result3 = twoSum(example3, 6);
	auto expect3 = std::vector<int>({0, 1});
	EXPECT_EQ(twoSum(example3, 6), std::vector<int>({0, 1}));

	auto example4 = std::vector<int>({54, 45, 2, 5, 3, 5, 4});
	auto result4 = twoSum(example4, 6);
	auto expect4 = std::vector<int>({2, 6});
	EXPECT_EQ(twoSum(example4, 6), std::vector<int>({2, 6}));
}