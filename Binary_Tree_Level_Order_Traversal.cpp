/*
Author: Timon Cui, timonbaby@163.com

Title: Binary Tree Level Order Traversal

Description:

Difficulty rating: Medium

Source:
http://www.leetcode.com/onlinejudge
http://www.leetcode.com/2010/09/printing-binary-tree-in-level-order.html

Notes:

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> cur;
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
            Q.push(NULL);
        }
        while (!Q.empty()) {
            TreeNode *top = Q.front();
            Q.pop();
            if (top == NULL) {
                result.push_back(cur);
                cur.clear();
                if (!Q.empty()) Q.push(NULL);
            } else {
                cur.push_back(top->val);
                if (top->left) Q.push(top->left);
                if (top->right) Q.push(top->right);
            }
        }
        return result;
    }
};