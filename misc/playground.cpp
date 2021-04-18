//
// Created by Bill Chen on 2021/4/5.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Do the preorder traversal for the binary tree.
 * @param root The only root node of the binary tree.
 */
void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    preorder(root->left);
    cout << root->val << endl;
    preorder(root->right);
}

class Student {
private:
    string name;
    int age;
public:
    Student(const string &name, int age) : name(name), age(age) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Student::age = age;
    }
};


void func1(Student *object){
    object->setAge(25);
    cout << object << endl;
}


int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    preorder(root);

    Student *billchen = new Student("Bill Chen", 2000);
    func1(billchen);
    cout << billchen << "::" << billchen->getAge();

    int a = 12, b = 13;
    int * const pa = &a;
    const int*  pb = &a;



}