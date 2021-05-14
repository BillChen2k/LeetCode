#include "header.h"
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (54.71%)
 * Likes:    1368
 * Dislikes: 0
 * Total Accepted:    317.3K
 * Total Submissions: 578.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
	bool solve(TreeNode *pa, TreeNode *pb) {
		if (!pa && !pb) {
			// Two null
			return true;
		}
		if (!pa || !pb) {
			// One of them is null
			return false;
		}
		return pa->val == pb->val && solve(pa->left, pb->right) && solve(pa->right, pb->left);
	}
	
	bool isSymmetric(TreeNode *root) {
		TreeNode *pa = root, *pb = root;
		return solve(pa, pb);
	}
};

// @lc code=end
int main() {
	TreeNode *root = lc::stringToTreeNode("[5,4,1,null,1,null,4,2,null,2,null]");
	cout << Solution().isSymmetric(root);
}