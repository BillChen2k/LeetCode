#include "header.h"
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.00%)
 * Likes:    2379
 * Dislikes: 0
 * Total Accepted:    623.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	bool isValid(string s) {
		stack<char> stk;
		unordered_map<char, char> pairs = {
		    {')', '('},
		    {']', '['},
		    {'}', '{'}};
		for (auto &one : s) {
			switch (one) {
			case '(':
			case '[':
			case '{':
				stk.push(one);
				break;
			case ']':
			case '}':
			case ')':
				if (!stk.empty() && stk.top() == pairs[one]) {
					stk.pop();
				} else {
					return false;
				}
			}
		}
		return stk.empty();
	}
};
// @lc code=end
