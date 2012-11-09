/*
Author: Timon Cui, timonbaby@163.com

Title: Construct Binary Tree from Preorder and Inorder Traversal

Description:
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Difficulty rating:

Source:
http://www.leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html
http://www.leetcode.com/onlinejudge

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
  typedef vector<int>::iterator Iter;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, preorder.begin(), preorder.end(), inorder, inorder.begin(), inorder.end());
  }
private:
  TreeNode *buildTree(vector<int> &preorder, Iter pre_begin, Iter pre_end, vector<int> &inorder, Iter in_begin, Iter in_end) {
    if (pre_begin == pre_end) return NULL;
    TreeNode *root = new TreeNode(*pre_begin);
    Iter in_root = find(in_begin, in_end, root->val);
    int left_nodes = in_root - in_begin;
    root->left = buildTree(preorder, pre_begin + 1, pre_begin + 1 + left_nodes, inorder, in_begin, in_root);
    root->right = buildTree(preorder, pre_begin + 1 + left_nodes, pre_end, inorder, in_root + 1, in_end);
    return root;
  }
};
