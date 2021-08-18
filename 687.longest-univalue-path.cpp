#include "header.h"
/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (43.90%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 82.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 * 
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
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
    int solve(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int lp = 0, rp = 0;
        if (root->left && root->left->val == root->val) {
            lp = l + 1;
        }
        if (root->right && root->right->val == root->val) {
            rp = r + 1;
        }
        ans = max(ans, lp + rp);
        return max(lp, rp);
    }

	int longestUnivaluePath(TreeNode *root) {
        if (!root) {
            return 0;
        }
        solve(root);
        return ans;
    }
};
// @lc code=end
