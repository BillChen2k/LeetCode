#include "header.h"
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    132.9K
 * Total Submissions: 222.7K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start

template <typename T>
void printer(vector<T> &src) {
	for (auto one : src) {
		cout << one << " ";
	}
	cout << endl;
}

class Solution {
      public:
	int partition(vector<int> &nums, int p, int r) {
        // swap;
        int index = p + rand() % (r - p);
        swap(nums[r], nums[index]);
		int pivot = nums[r];
		int i = p;
		for (int j = p; j <= r - 1; j++) {
			if (nums[j] < pivot) {
				swap(nums[j], nums[i]);
				i++;
			}
		}
		swap(nums[r], nums[i]);
		return i;
	}

	/**
     * @brief Applying quick sort between [p...r]
     * 
     * @param nums 
     * @param p 
     * @param r 
     */
	void quick_sort(vector<int> &nums, int p, int r) {
		// printer<int>(nums);
		if (p < r) {
			int i = partition(nums, p, r);
			quick_sort(nums, p, i - 1);
			quick_sort(nums, i + 1, r);
		}
	}

	vector<int> sortArray(vector<int> &nums) {
		quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}
};
// @lc code=end

int main() {
	Solution s;
	vector<int> a = {5, 2, 3, 1};
	s.sortArray(a);
}