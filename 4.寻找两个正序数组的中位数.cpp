/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.40%)
 * Likes:    2949
 * Dislikes: 0
 * Total Accepted:    228.6K
 * Total Submissions: 595.1K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
      public:
	vector<int> n1;
	vector<int> n2;
	int todel = 0;
	int del = 0;

	double findCenter(int offset1, int offset2) {
		del = offset1 + offset2;
		if (offset1 > n1.size() - 1 || n1.size() == 0) {
			return n2[todel - n1.size()];
		}
		if (offset2 > n2.size() - 1 || n2.size() == 0) {
			return n1[todel - n2.size()];
		}
		if (todel == del) {
			return n1[offset1] < n2[offset2] ? n1[offset1] : n2[offset2];
		}
		if (n1[offset1] >= n2[offset2]) {
			offset2 += min(((todel - del) / 2 < 1 ? 1 : (todel - del) / 2), max(int(n2.size() / 2), 1));
			// offset2++;

		} else {
			offset1 += min(((todel - del) / 2 < 1 ? 1 : (todel - del) / 2), max(int(n1.size() / 2), 1));
			// offset1++;
		}
		return findCenter(offset1, offset2);
	}

	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		n1 = nums1;
		n2 = nums2;
		int s1 = n1.size(), s2 = n2.size();
		if ((s1 + s2) % 2 != 0) {
			todel = (s1 + s2) / 2;
			// return findCenter((todel - del) / 2, todel - (todel - del) / 2);
			return findCenter(0, 0);
		} else {
			todel = (s1 + s2) / 2 - 1;
			double a = findCenter(0, 0);
			todel++;
			double b = findCenter(0, 0);
			return (a + b) / 2;
		}
	}
};
// @lc code=end

int main() {
	Solution s;
	// vector<int> a({1,5});
	// vector<int> b({2,3,4,6,7,8,9});
	vector<int> a({1});
	vector<int> b({1});
	cout << s.findMedianSortedArrays(a, b);
}
