#include "header.h"
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.19%)
 * Likes:    851
 * Dislikes: 0
 * Total Accepted:    297.5K
 * Total Submissions: 463.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层序遍历结果：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
        for(auto &one : vec) {
            if (one) {
                res.push_back(one->val);
            }
        }
        return res;
    }

	vector<vector<int>> levelOrder(TreeNode *root) {

		vector<vector<int>> ans;
		vector<TreeNode *> layer;
		if (!root) {
			return ans;
		}
        layer.push_back(root);
        while(layer.size() > 0) {
            vector<int> layerNum = listToNum(layer);
            if (layerNum.size()) ans.push_back(layerNum);
            vector<TreeNode *> next;
            for (auto &one: layer) {
                if (one) {
                    next.push_back(one->left);
                    next.push_back(one->right);
                }
            }
            layer = next;
        }
        return ans;
	}
};
// @lc code=end
