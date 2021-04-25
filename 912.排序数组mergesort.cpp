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

	void mergeSort(vector<int> &nums, int l, int r) {
		if (l > r) {
			return;
		}
		int mid = (l + r) >> 1;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid + 1, r);
		if (l == r) return;
	}
	
	vector<int> sortArray(vector<int> &nums) {
		// quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}
};
// @lc code=end

int main() {
	Solution s;
	vector<int> a = {5, 2, 3, 1};
	s.sortArray(a);
}