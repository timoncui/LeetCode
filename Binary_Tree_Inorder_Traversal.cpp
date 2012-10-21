/*
Author: Timon Cui, timonbaby@163.com

Title: Binary Tree Inorder Traversal

Description:

Difficulty rating: Hard

Notes: Easy for recursive solution. A little tricky for iterative solution.

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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> S;
    TreeNode* n = root;
    while (n || !S.empty()) { 
      if (n) {
	S.push(n);
	n = n->left;
      }
      if (!n) {
	n = S.top();
	S.pop();
	result.push_back(n->val);
	n = n->right;
      }
    }
    return result;
  }
};
