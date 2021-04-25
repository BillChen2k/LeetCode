#include "header.h"

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (65.72%)
 * Likes:    1643
 * Dislikes: 0
 * Total Accepted:    526.3K
 * Total Submissions: 800.7K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if ((!l1) || (!l2)) {
			return l1 ? l1 : l2;
		}
		ListNode head;
		ListNode *tail = &head;
		ListNode *pa = l1, *pb = l2;
		while (pa && pb) {
			if (pa->val < pb->val) {
				tail->next = pa;
				pa = pa->next;
			} else {
				tail->next = pb;
				pb = pb->next;
			}
			tail = tail->next;
		}
		tail->next = (pa ? pa : pb);
		return head.next;
	}
};
// @lc code=end
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	Solution s;
	ListNode *m = s.mergeTwoLists(p1, p2);
	return 0;
}