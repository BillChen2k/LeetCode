/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.99%)
 * Likes:    1284
 * Dislikes: 0
 * Total Accepted:    290.9K
 * Total Submissions: 363.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<vector<int> > ans;

	// p: Current position of the original array.
	void solve(vector<int> &nums, vector<int>& current, int p) {
		if (p == nums.size()) {
			ans.push_back(current);
			return;
		}
		solve(nums, current, p + 1);
		current.push_back(nums[p]);
		solve(nums, current, p + 1);
		current.pop_back();
	}

	vector<vector<int>> subsets(vector<int> &nums) {
		vector<int> current;
		solve(nums, current, 0);
		return ans;
	}
};
// @lc code=end

