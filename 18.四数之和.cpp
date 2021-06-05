#include "header.h"
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (40.21%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    175K
 * Total Submissions: 435K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：答案中不可以包含重复的四元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<vector<int>> ans;

	void dfs(const vector<int> &nums, vector<int> &current, int sum, int left, int &target) {
		if (current.size() == 4 && sum == target) {
			ans.push_back(current);
			return;
		}
		for (int i = left; i < nums.size(); i++) {
            if (current.size() + nums.size() - i < 4) {
                return;
            }
			if (i > left && nums[i] == nums[i - 1]) { // 去重
				continue;
			}
            // Must convert to int explicitly. -> Because size is unsigned int.
			if (i + 1 < nums.size() && sum + nums[i] + int(3 - current.size()) * nums[i + 1] > target) {
				return;
			}
			if (i + 1 < nums.size() && sum + nums[i] + int(3 - current.size()) * *nums.rbegin() < target) {
				continue;
			}
			current.push_back(nums[i]);
			dfs(nums, current, sum + nums[i], i + 1, target);
			current.pop_back();
		}
	}
    
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> current;
		dfs(nums, current, 0, 0, target);
		return ans;
	}
};
// @lc code=end
