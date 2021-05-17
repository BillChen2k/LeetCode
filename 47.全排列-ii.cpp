#include "header.h"
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (63.04%)
 * Likes:    665
 * Dislikes: 0
 * Total Accepted:    155.6K
 * Total Submissions: 246.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 */

// @lc code=start
class Solution {
      private:
	vector<vector<int>> result;
	void permute(vector<int> &nums, vector<int>& used, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (used[i] || i > 0 && nums[i] == nums[i - 1] && used[i - 1]) {
                continue;
            }
            perm.push_back(nums[i]);
            used[i] = 1;
            permute(nums, used, perm);
            used[i] = 0;
            perm.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(10), perm;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
        permute(nums, used, perm);
        return result;
    }
};
// @lc code=end


int main() {
    vector<int> a = {1,2,2,2};
    Solution().permuteUnique(a);
}