#include "header.h"
/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (47.14%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 65.5K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * 输出: 
 * "apple"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * 输出: 
 * "a"
 * 
 * 
 * 说明:
 * 
 * 
 * 所有输入的字符串只包含小写字母。
 * 字典的大小不会超过 1000。
 * 所有输入的字符串长度不会超过 1000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief Check if b is a subsequence of a.
     * 
     * @param a 
     * @param b 
     * @return string 
     */
    bool isSub(string a, string b) {
        int start = 0;
        for(int i = 0; i < b.size(); i++) {
            auto it = a.find(b[i], start);
            start = it + 1;
            if (it == string::npos) {
                return false;
            }
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int maxl = 0;
        for(auto& one: dictionary) {
            if (isSub(s, one)) {         
                if (one.size() > maxl) {
                    maxl = one.size();
                    ans = one;
                }
                else if(one.size() == maxl) {
                    ans = min(ans, one);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

