#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
      public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;
		int maxlen = 1;
		int left, len;
		for (left = 0; left < s.size() - 1; left++) {
			for (len = 2; len <= s.size() - left; len++) {
				string sub = s.substr(left, len - 1);
				if (sub.find(s[left + len - 1]) != -1) {
					break;
				} else {
					maxlen = max(maxlen, len);
				}
			}
		}
		return maxlen;
	}
};
// @lc code=end

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("pkwpkw");
	return 0;
}