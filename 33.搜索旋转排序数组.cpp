#include "header.h"
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.68%)
 * Likes:    1359
 * Dislikes: 0
 * Total Accepted:    278.7K
 * Total Submissions: 668.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 * 
 */

// @lc code=start
class Solution {
      public:
      // Not Used.
	int findSplit(vector<int> &nums, int left, int right) {
		if (left >= right) {
			return -1;
		}
		int mid = (left + right) >> 1;
		if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
			// Rotate point found
			return mid;
		} else {
			int leftRes = findSplit(nums, left, mid - 1);
			if (leftRes != -1)
				return leftRes;
			int rightRes = findSplit(nums, mid + 1, right);
			if (rightRes != -1)
				return rightRes;
		}
		return right;
	}

	int binarySearch(vector<int> nums, int left, int right, int target) {
		if (left > right) {
			return -1;
		}
		bool is_ordered = nums[left] < nums[right];
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			return mid;
		}

		if (is_ordered) {
			return nums[mid] > target ? binarySearch(nums, left, mid - 1, target) : binarySearch(nums, mid + 1, right, target);
		}

        else {
			/**
             * Three scenarios to consider when searching for the right side:
             * 1. [ 5 6 <mid> 7 <target> 8 1 2 3 4]
             * 2. [ 5 6 <mid> 7 8 1 2 3 <target> 4]
             * 3. [ 5 6 7 8 1 <mid> 2 3 <target> 4]
             * 
             */
			if (
			    (nums[mid] < target && nums[mid] > nums[left] && target >= nums[left]) ||
			    (nums[mid] > target && nums[mid] >= nums[left] && target <= nums[right]) ||
			    (nums[mid] < target && nums[mid] < nums[right] && target <= nums[right])
            ) {
				return binarySearch(nums, mid + 1, right, target);
			} else {
				return binarySearch(nums, left, mid - 1, target);
			}
	}
	}

	int search(vector<int> &nums, int target) {
		// Find the rotate point
		return binarySearch(nums, 0, nums.size() - 1, target);
	}
};
// @lc code=end

int main() {
	vector<int> a = {3,1};
	// int t = Solution().findSplit(a, 0, a.size() - 1);
	int s = Solution().search(a, 1);
	return 0;
}