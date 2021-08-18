#include "header.h"
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (54.72%)
 * Likes:    766
 * Dislikes: 0
 * Total Accepted:    137.5K
 * Total Submissions: 251.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 * 
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
      public:
	int ans = 0;

    /**
     * @brief Single solve: returns the longest path of left or right.
     * 
     * @param root 
     * @return int 
     */
	int solve(TreeNode *root) {
		if (!root) {
			return 0;
		}
		int l = 0, r = 0;
		if (root->left) {
			l = solve(root->left) + 1;
		}
		if (root->right) {
			r = solve(root->right) + 1;
	    }
		ans = max(ans, l + r);
        return max(l, r);
	}

	int diameterOfBinaryTree(TreeNode *root) {
        solve(root);
        return ans;
	}
};
// @lc code=end
