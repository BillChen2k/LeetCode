#include "header.h"
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (55.70%)
 * Likes:    682
 * Dislikes: 0
 * Total Accepted:    207.5K
 * Total Submissions: 372.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
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

struct res {
    int depth;
    bool is_balenced;
    res(int d, bool b) : depth(d), is_balenced(b) {}
};

class Solution {
public:

    res* solve(TreeNode *root) {
        if (!root) {
            return new res(0, true);
        }
        auto leftres = solve(root->left);
        auto rightres = solve(root->right);
        return new res(max(leftres->depth, rightres->depth) + 1, 
            leftres->is_balenced && rightres->is_balenced && abs(leftres->depth - rightres->depth) <= 1);
    }

    bool isBalanced(TreeNode* root) {
        auto result = solve(root);
        return result->is_balenced;
    }
};
// @lc code=end

