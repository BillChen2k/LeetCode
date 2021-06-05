#include "header.h"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (55.86%)
 * Likes:    2389
 * Dislikes: 0
 * Total Accepted:    254.7K
 * Total Submissions: 454.8K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:

    /**
     * @brief Stack Structure : [ left, top ]
     * 
     * @param height 
     * @return int 
     */
	int trap(vector<int> &height) {
		// height.push_back(-1); // Pivot
		vector<int> h(height.size(), 0);
		stack<int> stk; // Mono Stack, stores the index
        int ans = 0;
		for (int i = 0; i < height.size(); i++) {
			while (!stk.empty() && height[i] > height[stk.top()]) {
				int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int width = i - left - 1;
                int hi = min(height[left], height[i]) - height[top];
                ans += width * hi;
			}
			stk.push(i);
		}
        return ans;
	}
};
// @lc code=end