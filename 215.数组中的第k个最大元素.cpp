#include "header.h"
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.59%)
 * Likes:    1075
 * Dislikes: 0
 * Total Accepted:    332.7K
 * Total Submissions: 515.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
      public:

	// Partition [l, r]
	int partition(vector<int> &nums, int l, int r) {
		if (l >= r) {
			return l;
		}
		int pivot_index = l + rand() % (r - l + 1);
		int pivot = nums[pivot_index];
		swap(nums[r], nums[pivot_index]);
		int split_index = l;
		for (int i = l; i <= r - 1; i++) {
			if (nums[i] < pivot) {
				swap(nums[i], nums[split_index++]);
			}
		}
		swap(nums[r], nums[split_index]);
		return split_index;
	}

	int findKthLargest(vector<int> &nums, int k) {
		int v = partition(nums, 0, nums.size() - 1);
		k = nums.size() - k;
		while (v != k) {
			if (v < k) {
				v = partition(nums, v + 1, nums.size() - 1);
			} else {
				v = partition(nums, 0, v - 1);
			}
		}
		return nums[v];
	}
};
// @lc code=end

int main() {
	vector<int> test = {2, 1};
	int split = Solution().findKthLargest(test, 1);
	return 0;
}
