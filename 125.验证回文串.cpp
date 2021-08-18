#include "header.h"
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (47.19%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    234.5K
 * Total Submissions: 496.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
      public:

	bool solve(string &s, int left, int right) {
		if (left >= right) {
			return true;
		}
		if (s[left] == s[right]) {
			return solve(s, left + 1, right - 1);
		} else {
			return false;
		}
	}

	bool isPalindrome(string s) {
		if (s.size() == 0) {
			return true;
		}
		string filteredS;
		for (auto &ch : s) {
			if (isalnum(ch)) {
				filteredS += tolower(ch);
			}
		}
		return solve(filteredS, 0, filteredS.size() - 1);
	}
};
// @lc code=end
