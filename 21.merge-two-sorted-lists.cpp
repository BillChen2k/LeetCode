#include "header.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.57%)
 * Likes:    1857
 * Dislikes: 0
 * Total Accepted:    668.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a sorted list. The list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [], l2 = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev = new ListNode();
        ListNode *ans = prev;
        prev->next = l1;
        while(prev->next || l2) {
            if (!l2) {
                break;
            }
            if (prev->next) {
                if (prev->next->val > l2->val) {
                    // Insert l2
                    auto next = prev->next;
                    auto l2next = l2->next;
                    prev->next = l2;
                    l2->next = next;
                    l2 = l2next;
                }
                else {
                    prev = prev->next;
                }
            }
            else {
                prev->next = l2;
                break;
            }
        }
        return ans->next;
    }
};
// @lc code=end

