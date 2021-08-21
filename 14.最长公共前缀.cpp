#include "header.h"
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.44%)
 * Likes:    1589
 * Dislikes: 0
 * Total Accepted:    512.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string solve(const vector<string>& strs, int left, int right) {
        if (left >= right) {
            return strs[left];
        }
        int mid = (left + right) >> 1;
        string leftCommon = solve(strs, left, mid);
        string rightCommon = solve(strs, mid + 1, right);
        string common = "";
        for (int i = 0; i < min(leftCommon.size(), rightCommon.size()); i++) {
            if (leftCommon[i] == rightCommon[i]) {
                common += leftCommon[i];
            }
            else {
                break;
            }
        }
        return common;
    }
    string longestCommonPrefix(vector<string>& strs) {
        return solve(strs, 0 , strs.size() - 1);
    }
};

// @lc code=end

