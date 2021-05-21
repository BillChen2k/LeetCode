/**
 * @file 41.缺失的第一个正数.cpp
 * @author Bill Chen (Bill.Chen@live.com)
 * @brief 微软笔试题第三题。曾使用 unordered_map，但复杂度过高超时
 * @version 0.1
 * @date 2021-05-22 01:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "header.h"
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (41.01%)
 * Likes:    1081
 * Dislikes: 0
 * Total Accepted:    132.2K
 * Total Submissions: 322.1K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        for(auto &one : nums) {
            if (one > 0 && ans - 1 > one) {
                ans = one;
            }
        }
    }
};
// @lc code=end

