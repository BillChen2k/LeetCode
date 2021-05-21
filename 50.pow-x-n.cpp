#include "header.h"
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    648
 * Dislikes: 0
 * Total Accepted:    183.9K
 * Total Submissions: 490.7K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100.0 
 * -2^31 
 * -10^4 
 * 
 * 
 */

// @lc code=start

typedef long long ll;

class Solution {
      public:
	/**
     * @brief Quick pow for n >= 0
     * 
     * @param x 
     * @param n 
     * @return double 
     */
	double quickPow(double x, int n) {
		if (n == 1) {
			return x;
		}
		if (n == 0) {
			return 1;
		}
		double nextPow = quickPow(x, n / 2);
		if (n % 2 == 0) {
			return nextPow * nextPow;
		} else {
			return x * nextPow * nextPow;
		}
	}

    /**
     * @brief Quick power, for n < 0;
     * 
     * @param x 
     * @param n 
     * @return double 
     */
	double quickPowMinus(double x, int n) {
        long nl = n;
		if (n == -1) {
			return 1 / x;
		}
		if (n == 0) {
			return 1;
		}
		double nextPow = quickPowMinus(x, n / 2);
		if (-nl % 2 == 0) {
			return nextPow * nextPow;
		} else {
			return (1 / x) * nextPow * nextPow;
		}
	}

	double myPow(double x, int n) {
		if (n == 0 || x == 1) {
			return 1;
		}
		if (n >= 0) {
			return quickPow(x, n);
		} else {
            return quickPowMinus(x, n);
		}
	}
};
// @lc code=end
