//
// Created by Bill Chen on 2021/4/5.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> inorder_index;

    /**
     * Get the element position of an vector.
     * @param vec
     * @param ele
     * @return
     */
    int pos(vector<int> &vec, int ele) {
        auto itr = find(vec.begin(), vec.end(), ele);
        if (itr != vec.end()) {
            return distance(vec.begin(), itr);
        }
        else {
            return -1;
        }
    }

    TreeNode* construct(int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || pre_right > preorder.size()) {
            return NULL;
        }
        int pre_root = pre_left;
        int in_root = inorder_index[preorder[pre_root]];
        int size_left = in_root - in_left;
        TreeNode* root = new TreeNode(preorder[pre_root]);

        root->left = construct(pre_left + 1,  pre_left + size_left, in_left, in_root - 1);
        root->right = construct(pre_left + size_left + 1, pre_right, in_root + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        if (preorder.size() == 0) {
            return NULL;
        }
        // Build a hash map of value of inorder -> index in the map.
        for(int i = 0; i < inorder.size(); i++){
            inorder_index[inorder[i]] = i;
        }
        return construct(0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }
    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}