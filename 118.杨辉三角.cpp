#include "header.h"
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (70.90%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    170.5K
 * Total Submissions: 240.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i< numRows; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = 1, ans[i][i] = 1;
            if (i > 0) {
                for(int j = 1; j <= i / 2; j++) {
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                    ans[i][i - j] = ans[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

