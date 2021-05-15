#include "header.h"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (46.88%)
 * Likes:    772
 * Dislikes: 0
 * Total Accepted:    153.3K
 * Total Submissions: 326.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
      
	enum direction {
		right,
		left,
		up,
		down
	};

	unordered_map<direction, pair<int, int>> directions = {
	    {right, {1, 0}},
	    {left, {-1, 0}},
	    {up, {0, -1}},
	    {down, {0, 1}}};

	void spiral(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y, direction d, vector<int> &ans) {
		if (ans.size() == matrix.size() * matrix[0].size()) {
			return;
		}
		ans.push_back(matrix[y][x]);
		visited[y + 1][x + 1] = true;
		direction next_direction = d;
		switch (d) {
		case right:
			if (visited[y + 1][x + 2]) {
				next_direction = down;
			}
			break;
		case left:
			if (visited[y + 1][x]) {
				next_direction = up;
			}
			break;
		case down:
			if (visited[y + 2][x + 1]) {
				next_direction = left;
			}
			break;
		case up:
			if (visited[y][x + 1]) {
				next_direction = right;
			}
		}
        spiral(matrix, visited, 
        x + directions[next_direction].first, y + directions[next_direction].second, 
        next_direction, ans);
	}

	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		vector<int> ans;
		// Let all four border equals false;
		vector<vector<bool>> visited(matrix.size() + 2, vector<bool>(matrix[0].size() + 2, false));
		for (int i = 0; i < visited[0].size(); i++) {
			visited[0][i] = true;
			visited[visited.size() - 1][i] = true;
		}
		for (int i = 0; i < visited.size(); i++) {
			visited[i][0] = true;
			visited[i][visited[0].size() - 1] = true;
		}
        spiral(matrix, visited, 0, 0, right, ans);
        return ans;
	}
};
// @lc code=end
