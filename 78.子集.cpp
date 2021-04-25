#include "header.h"
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.80%)
 * Likes:    1149
 * Dislikes: 0
 * Total Accepted:    238.5K
 * Total Submissions: 298.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<vector<int>> subsets(vector<int> &nums) {
		unsigned int bit = 0;
		vector<vector<int>> ans;
		while (bit < (1 << nums.size())) {
			vector<int> res;
			for (int i = 0; i < nums.size(); i++) {
				if (((bit >> i) & 1) == 1) {
					res.push_back(nums[i]);
				}
			}
            ans.push_back(res);
			bit++;
		}
        return ans;
	}
};
// @lc code=end
int main() {
    Solution s;
    cout << (1 << 1) << " " << (2 & 2);
    vector<int> arr = {1,2,3,4};
    s.subsets(arr);
    return 0;
}