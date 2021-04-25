#include "header.h"
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (54.91%)
 * Likes:    1274
 * Dislikes: 0
 * Total Accepted:    248.5K
 * Total Submissions: 452.4K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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

    ListNode *merge(vector<ListNode *> &lists, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        if (left == right) {
            return lists[left];
        }
        int mid = (left + right) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }


	ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        return merge(lists, 0, lists.size() - 1);
	}
};
// @lc code=end
