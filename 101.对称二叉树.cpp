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
	bool isLayerSymmetric(vector<TreeNode *> &layer) {
		for (int i = 0; i < layer.size() / 2; i++) {
			if (layer[i] == nullptr && layer[layer.size() - i - 1] != nullptr) {
				return false;
			}
			if (layer[i] != nullptr && layer[layer.size() - i - 1] == nullptr) {
				return false;
			}
			if (layer[i] == nullptr && layer[layer.size() - i - 1] == nullptr) {
				continue;
			}
			if (layer[i]->val != layer[layer.size() - i - 1]->val) {
				return false;
			}
		}
		return true;
	}

	bool isSymmetric(TreeNode *root) {
		queue<TreeNode *> Q;
		Q.push(root);
		while (!Q.empty()) {
			vector<TreeNode *> layer;
			while (!Q.empty()) {
				layer.push_back(Q.front());
				Q.pop();
			}
			if (!isLayerSymmetric(layer)) {
				return false;
			}
			for (auto &one : layer) {
				if (one != nullptr) {
					Q.push(one->left);
				}
				if (one != nullptr) {
					Q.push(one->right);
				}
			}
		}
		return true;
	}
};
// @lc code=end
