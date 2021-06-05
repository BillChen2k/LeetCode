#include "header.h"
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    1396
 * Dislikes: 0
 * Total Accepted:    403.6K
 * Total Submissions: 961.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 
 * 0 
 * 1 
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
    // Use a dummyHead to avoid null.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *p0 = head, *p1 = head;
        ListNode *p1pre = dummyHead;
        for (int i = 0; i < n; i++) {
            p0 = p0->next;
        }
        while(p0 != NULL) {
            p0 = p0->next;
            p1 = p1->next;
            p1pre = p1pre->next;
        }
        // Delete p1
        p1pre->next = p1->next;
        return dummyHead->next;
    }
};
// @lc code=end

