#include "header.h"
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.11%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    133.7K
 * Total Submissions: 234.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
	vector<int> listToNum(vector<TreeNode *> &vec) {
		vector<int> res;
		for (auto &one : vec) {
			if (one) {
				res.push_back(one->val);
			}
		}
		return res;
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> ans;
		vector<TreeNode *> layer;
		if (!root) {
			return ans;
		}
		bool to_right = false;
		layer.push_back(root);
		while (layer.size() > 0) {
			vector<int> layerNum = listToNum(layer);
			if (layerNum.size())
				ans.push_back(layerNum);
			vector<TreeNode *> next;
			if (to_right) {
				for (int i = layer.size() - 1; i >= 0; i--) {
                    auto one = layer[i];
					if (one) {
						next.push_back(one->left);
						next.push_back(one->right);
					}
				}
			} else {
				for (int i = layer.size() - 1; i >= 0; i--) {
                    auto one = layer[i];
					if (one) {
						next.push_back(one->right);
						next.push_back(one->left);
					}
				}
			}
			layer = next;
			to_right = !to_right;
		}
		return ans;
	}
};
// @lc code=end
