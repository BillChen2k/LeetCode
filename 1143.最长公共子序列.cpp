#include "header.h"
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (62.32%)
 * Likes:    529
 * Dislikes: 0
 * Total Accepted:    113.8K
 * Total Submissions: 182.5K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 
 * 
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 
 * 
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * text1 和 text2 仅由小写英文字符组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  /**
     * @brief Calculating LCS.
     * 
     * dp[i][j] = { 
     *     0, i == 0 || j == 0;
     *     dp[i - 1][j - 1], text[i] == text[j];
     *     max(dp[i - 1][j], dp[i][j - 1]), text[i] != text[j];
     * 
     * }
     * 
     * @param text1 
     * @param text2 
     * @return int The length of lCS.
     */
  int longestCommonSubsequence(string text1, string text2) {
	  vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
	  for (int i = 1; i <= text1.size(); i++) {
		  for (int j = 1; j <= text2.size(); j++) {
			  if (text1[i - 1] == text2[j - 1]) {
				  dp[i][j] = dp[i - 1][j - 1] + 1;
			  } else {
				  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			  }
		  }
	  }
	  return dp[text1.size()][text2.size()];
    }
};
// @lc code=end

