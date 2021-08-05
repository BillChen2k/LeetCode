#include "header.h"
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (45.44%)
 * Likes:    466
 * Dislikes: 0
 * Total Accepted:    151.5K
 * Total Submissions: 333.2K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
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
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	bool binarySearch(vector<int> &arr, int target, int low, int high) {
		if (low >= high) {
			return arr[low] == target;
		}
		int mid = (low + high) >> 1;
		if (arr[mid] > target) {
			return binarySearch(arr, target, low, mid - 1);
		} else if (arr[mid] < target) {
			return binarySearch(arr, target, mid + 1, high);
		} else {
			return true;
		}
	}

	bool findRow(vector<vector<int>> &matrix, int target, int low, int high) {
		if (low >= high - 1) {
            cout << low;
			return binarySearch(matrix[low], target, 0, matrix[low].size() - 1);
		}
		int mid = (low + high) >> 1;
		if (matrix[mid][0] > target) {
			return findRow(matrix, target, low, mid - 1);
		} else {
			return findRow(matrix, target, mid, high);
		}
	}

	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		return findRow(matrix, target, 0, matrix.size() - 1);
	}
};
// @lc code=end
int main() {
	auto arr = lc::stringToIntegerVector("[10,11,16,20]");
	cout << Solution().binarySearch(arr, 13, 0, arr.size() - 1);
}
