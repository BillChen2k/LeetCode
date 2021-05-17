#include "header.h"
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (45.52%)
 * Likes:    929
 * Dislikes: 0
 * Total Accepted:    232.3K
 * Total Submissions: 510.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * intervals[i].length == 2
 * 0 i i 
 * 
 * 
 */

// @lc code=start
class Solution {
      public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end(), [&](vector<int> lhs, vector<int> rhs) {
			if (lhs[0] != rhs[0]) {
				return lhs[0] < rhs[0];
			} else {
				return lhs[1] < rhs[1];
			}
		});
		for(auto &one : intervals) {
            if (ans.empty()) {
                ans.emplace_back(one);
                continue;
            }
            auto& last = ans.back();
            if (last[1] >= one[0]) {
                last[1] = max(one[1], last[1]);
            }
            else {
                ans.emplace_back(one);
            }
        }
		return ans;
	}
};
// @lc code=end

int main() {
	vector<vector<int>> a = {
	    {1, 4},
	    {1, 5}};
	Solution().merge(a);
}
