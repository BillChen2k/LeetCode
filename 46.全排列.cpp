#include "header.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.82%)
 * Likes:    1281
 * Dislikes: 0
 * Total Accepted:    295.6K
 * Total Submissions: 379.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {

      private:
	vector<vector<int>> result;
	void permute(vector<int> &nums, int pos, int len) {
		if (pos == len) {
			result.emplace_back(nums);
			return;
		}
		for (int i = pos; i < nums.size(); ++i) {
			swap(nums[i], nums[pos]);
			permute(nums, pos + 1, len);
			swap(nums[i], nums[pos]);
		}
	}

      public:

	vector<vector<int>> permute(vector<int> &nums) {
		permute(nums, 0, (int)nums.size());
		return result;
	}
};
// @lc code=end

int main() {
	Solution s;
	vector<int> a = {1, 2, 3};
	s.permute(a);
}