//
// Created by Bill Chen on 2021/2/19.
//
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

#include <iostream>
#include <vector>

using namespace std;

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:

    SegmentTreeNode * build(int start, int end, int maxv, vector<int> &A) {
        if (start > end) {
            return NULL;
        }
        SegmentTreeNode *node = new SegmentTreeNode(start, end, maxv);
        if (start == end) {
            node->max = A[start];
            return node;
        }
        /*
         * Erroneous: Used too much stack memory.
         */
        SegmentTreeNode *left = build(start, (start + end) / 2, A[start], A);
        SegmentTreeNode *right = build((start + end) / 2 + 1, end, A[(start + end) / 2], A);
        node->max = max(left->max, right->max);
        node->left = left;
        node->right = right;
        return node;
    }

    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        return build(0, A.size() - 1, 0, A);
        // write your code here
    }
};

int main() {

    vector<int> a {3, 2, 1, 4};
    Solution *s = new Solution();
    auto t = s->build(a);
    return 0;
}
