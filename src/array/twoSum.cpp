//
// Created by Artur Barilo on 27.07.2021.
//

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class solutionClass : public testing::Test {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> umap;
		for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
			int tmp = target - nums[i];
			if (umap.count(tmp)) {
				return std::vector<int>({umap[tmp], i});
			} else {
				umap[nums[i]] = i;
			}
		}

		return std::vector<int>();

	}
};

TEST_F(solutionClass, twoSum) {

	auto example1 = std::vector<int>({2, 7, 11, 15});
	auto result1 = twoSum(example1, 9);
	auto expect1 = std::vector<int>({0, 1});
	EXPECT_TRUE((result1 == expect1) || (result1[0] == expect1[1] && result1[1] == expect1[0]));

	auto example2 = std::vector<int>({3, 2, 4});
	auto result2 = twoSum(example2, 6);
	auto expect2 = std::vector<int>({1, 2});
	EXPECT_TRUE((result2 == expect2) || (result2[0] == expect2[1] && result2[1] == expect2[0]));

	auto example3 = std::vector<int>({3, 2, 4});
	auto result3 = twoSum(example3, 7);
	auto expect3 = std::vector<int>({0, 2});
	EXPECT_TRUE((result3 == expect3) || (result3[0] == expect3[1] && result3[1] == expect3[0]));

	auto example4 = std::vector<int>({54, 45, 2, 5, 3, 5, 4});
	auto result4 = twoSum(example4, 6);
	auto expect4 = std::vector<int>({2, 6});
	EXPECT_TRUE((result4 == expect4) || (result4[0] == expect4[1] && result4[1] == expect4[0]));
}