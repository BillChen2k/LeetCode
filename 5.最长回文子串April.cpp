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
		vector<vector<bool> > dp(s.size() + 5, vector<bool>(s.size() + 5, false));
		int maxl = 1;
		int begin = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			dp[i][i] = true;
		}
		for(int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				begin = i;
				maxl = 2;
			}
		}
		for(int L = 3; L <= s.size(); L++){
			for (int i = 0; i <= s.size() - L; i++) {
				if (s[i] == s[i + L - 1] && dp[i + 1][i + L - 2]) {
					dp[i][i + L - 1] = true;
					maxl = L;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxl);
	}
};
// @lc code=end
int main(){
	Solution s;
	cout << s.longestPalindrome("aaaa");
	return 0;
}