#include "header.h"
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (65.31%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    115.2K
 * Total Submissions: 176.4K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:

    int combination(double a, double b) {
        double ans = 1;
        for(int i = 0; i < b; i++) {
            ans *= ((a - i) / (i + 1));
        }
        return round(ans);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        ans[rowIndex] = 1;
        for(int i = 1; i <= rowIndex / 2; i++) {
            ans[i] = combination(rowIndex, i);
            ans[rowIndex - i] = ans[i];
        }
        return ans;
    }
};
// @lc code=end

