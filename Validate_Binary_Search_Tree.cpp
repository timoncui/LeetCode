/*
Author: Timon Cui, timonbaby@163.com

Title: Validate Binary Search Tree

Description:
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Difficulty rating: Easy

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
  bool isValidBST(TreeNode *root, int low, int high) {
    return !root || (root->val < high && root->val > low && isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high));
  }
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, INT_MIN, INT_MAX);        
  }
};
