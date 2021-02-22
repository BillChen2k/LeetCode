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
		int dp[1000][1000] = {0};
		for(int i =0; i < s.size(); i++) {
			dp[i][i] = 1;
		}
		int maxa = 0, maxb = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j< s.size(); j++) {
				if (s[i] == s[j] && j - i > 2) {

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