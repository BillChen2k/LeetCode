#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.12%)
 * Likes:    2482
 * Dislikes: 0
 * Total Accepted:    326.8K
 * Total Submissions: 1M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	string longestPalindrome(string s) {
		int maxa = 0;
		int maxb = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; i - j >= 0 && i + j < s.size(); j++) {
				if (s[i - j] == s[i + j]) {
					if (2 * j - 1 >= maxb - maxa) {
						maxb = i + j;
						maxa = i - j;
					}
				} else {
					break;
				}
			}
			for (int j = 1; i - j + 1 >= 0 && i + j < s.size(); j++) {
				if (s[i - j + 1] == s[i + j]) {
					if (2 * j - 1 >= maxb - maxa) {
						maxb = i + j;
						maxa = i - j + 1;
					}
				} else {
					break;
				}
			}
		}
		return s.substr(maxa, maxb - maxa + 1);
	}
};
// @lc code=end
int main(){
	Solution s;
	cout << s.longestPalindrome("aaaa");
	return 0;
}