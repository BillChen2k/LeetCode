#include "header.h"
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.66%)
 * Likes:    1325
 * Dislikes: 0
 * Total Accepted:    271.7K
 * Total Submissions: 479.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, string> keys = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    vector<string> ans;

    void solve(string& digits, string current, int len) {
        if (len == digits.size()) {
            ans.push_back(current);
            return;
        }
        int ch = digits[len] - '0';
        for(int i = 0; i < keys[ch].size(); i++) {
            current += keys[ch][i];
            solve(digits, current, len + 1);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return ans;
        }
        solve(digits, "", 0);
        return ans;
    }
};
// @lc code=end

int main() {
    Solution().letterCombinations("23");
}

