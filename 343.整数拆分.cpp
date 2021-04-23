#include "header.h"
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (59.59%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    83.9K
 * Total Submissions: 140.8K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

// @lc code=start

typedef unsigned long long ull;

class Solution {
public:
    int integerBreak(int n) {
        ull dp[60] = {0};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        if (n <= 6) {
            return dp[n];
        }
        for (int a = 7; a <= n; a ++) {
            dp[a] = max(dp[a - 2] * 2, max(dp[a - 3] * 3, dp[a - 4] * 4));
        }
        return dp[n];
    }

};
// @lc code=end

