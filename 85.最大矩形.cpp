#include "header.h"
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (51.68%)
 * Likes:    923
 * Dislikes: 0
 * Total Accepted:    79.9K
 * Total Submissions: 154.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix[0].length
 * 0 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	int maximalRectangle(vector<vector<char>> &matrix) {
		// Execute 84 for each row
		int maxsize = 0;
		for (int i = 0; i < matrix.size(); i++) {
			vector<int> heights(matrix[i].size(), 0);

            // Calculating the heights
			for (int j = 0; j < matrix[i].size(); j++) {
				for (int k = 0; k <= i; k++) {
					if (matrix[i - k][j] == '1') {
						heights[j]++;
					} else {
						break;
					}
				}
			}  
            
			// Using an ascending mono stack.
			stack<int> stk;
			heights.insert(heights.begin(), 0);
			heights.push_back(0);
			stk.push(0);
			for (int ii = 0; ii < heights.size(); ii++) {
				while (!stk.empty() && heights[ii] < heights[stk.top()]) {
					int top = stk.top();
					stk.pop();
					int left = stk.top();
                    int width = ii - left - 1;
                    int hi = heights[top];
                    maxsize = max(maxsize, width * hi);
				}
                stk.push(ii);
			}
		}
        return maxsize;
	}
};
// @lc code=end