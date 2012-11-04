/*
Author: Timon Cui, timonbaby@163.com

Title: Construct Binary Tree from Inorder and Postorder Traversal

Description:
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Difficulty rating: Median

Source:
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(inorder, inorder.begin(), inorder.end(), postorder, postorder.begin(), postorder.end());
  }   
private:
  TreeNode *buildTree(vector<int> &inorder, Iter in_begin, Iter in_end, vector<int> &postorder, Iter post_begin, Iter post_end) {
    if (post_begin == post_end) return NULL;
    TreeNode *root = new TreeNode(*(post_end - 1));
    Iter in_root = find(in_begin, in_end, root->val);;
    int left_nodes = in_root - in_begin;
    root->left = buildTree(inorder, in_begin, in_root, postorder, post_begin, post_begin + left_nodes);
    root->right = buildTree(inorder, in_root + 1, in_end, postorder, post_begin + left_nodes, post_end - 1);
  }
};
