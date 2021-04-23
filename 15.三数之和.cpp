#include "header.h"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.86%)
 * Likes:    3272
 * Dislikes: 0
 * Total Accepted:    491.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		if (nums.size() <= 2)
			return res;
		sort(nums.begin(), nums.end());

		int one = 0, two = 1, three = nums.size() - 1;
		for (int i = one; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			three = nums.size() - 1;
			for (int j = i + 1; j < nums.size() - 1; j++) {
				if (j > i + 1 && nums[j - 1] == nums[j])
					continue;
                if (j >= three) {
                    break;
                }
				while (nums[i] + nums[j] + nums[three] > 0 && three > j + 1) {
					three--;
                }
				if (nums[i] + nums[j] + nums[three] == 0) {
					res.push_back({nums[i], nums[j], nums[three]});
				}
			}
		}
		return res;
	}
	
}
;
// @lc code=end
