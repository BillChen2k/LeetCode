#include "header.h"
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (49.18%)
 * Likes:    1560
 * Dislikes: 0
 * Total Accepted:    256.4K
 * Total Submissions: 521.2K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以设计时间复杂度为 O(n^2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
class Solution {
      public:

	/**
	 * @brief Finding the first element from nums[0...bound] that is greater than the target
	 * 
	 * @param nums 
	 * @param bound 
	 * @param target 
	 * @return int The index of the target.
	 */
	int binarySearchForJ(vector<int> nums, int bound, int target) {
		int left = 0, right = bound;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}

	/**
	 * @brief Search for the first element in nums that is greater than target.
	 * 
	 * @param nums 
	 * @param bound 
	 * @param target 
	 * @return int 
	 */
	int linearSearchForJ(vector<int> nums, int bound, int target) {
		int j = 0;
		while (1) {
			if (nums[j] > target) {
				break;
			}
			j++;
		}
		return j;
	}

	/**
     * @brief Complexity: nlogn
     * 
     * @param nums 
     * @return int 
     */
	int lengthOfLIS(vector<int> &nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> tail(nums.size() + 1, 10000);
		int len = 0;
		tail[0] = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			int j = binarySearchForJ(tail, len + 1, nums[i]);
			if (j > 0 && nums[i] == tail[j - 1]) {
				// Equals to the end
				j--;
			}
			tail[j] = nums[i];
			if (j > len) {
				len++;
			}
		}
		return len + 1;
	}
};
// @lc code=end

int main() {
	vector<int> arr = {10, 9, 2, 5, 3, 4};
	Solution s;
	int ans = s.lengthOfLIS(arr);
	// vector<int> arr1 = {1,3,5,7,9,10,10};
	// cout << s.binarySearchForJ(arr1, 5, 6);
	return 0;
}