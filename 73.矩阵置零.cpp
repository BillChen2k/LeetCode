#include "header.h"
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (59.02%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    102.5K
 * Total Submissions: 173.7K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {

      public:
	// void setRow(vector<vector<int>> &matrix, int n) {
	// 	for (int i = 0; i < matrix[0].size(); i++) {
	// 		matrix[n][i] = 0;
	// 	}
	// }

	// void setColumn(vector<vector<int>> &matrix, int n) {
	// 	for (int i = 0; i < matrix.size(); i++) {
	// 		matrix[i][n] = 0;
	// 	}
	// }

	void setZeroes(vector<vector<int>> &matrix) {
		vector<bool> bits_row(matrix.size(), false);
		vector<bool> bits_col(matrix[0].size(), false);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (!matrix[i][j]) {
					bits_row[i] = bits_col[j] = true;
				}
			}
		}
        for (int i = 0; i < bits_row.size(); i++) {
            for(int j = 0; j < bits_col.size(); j++) {
                if (bits_row[i] || bits_col[j]) {
					matrix[i][j] = 0;
                }
            }
        }      
	}
};

// @lc code=end
