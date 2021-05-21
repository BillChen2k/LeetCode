#include "header.h"
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.14%)
 * Likes:    1788
 * Dislikes: 0
 * Total Accepted:    274.8K
 * Total Submissions: 356.2K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<string> ans;

	void generate(string& res, int n, int left, int right) {
		if (left == n && right == n) {
			ans.push_back(res);
			return;
		}
		if (left < n) {
			res += "(";
			generate(res, n, left + 1, right);
			res.pop_back();
		}
		if (right < n && left > right) {
			res += ")";
			generate(res, n, left, right + 1);
			res.pop_back();
		}
		return;
	}

	vector<string> generateParenthesis(int n) {
        string res = "(";
		generate(res, n, 1, 0);
		return ans;
	}
};
// @lc code=end
