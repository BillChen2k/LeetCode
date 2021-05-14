#include "header.h"
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (76.69%)
 * Likes:    580
 * Dislikes: 0
 * Total Accepted:    163.2K
 * Total Submissions: 212.6K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> &current, vector<bool> &used, int from, int n, int k) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }
        for (int i = from; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(i);
                solve(current, used, i + 1, n , k);
                current.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<bool> used(n + 5, false);
        solve(current, used, 1, n, k);
        return ans;
    }
};
// @lc code=end

