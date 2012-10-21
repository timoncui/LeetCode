/*
Author: Timon Cui, timonbaby@163.com

Title: Balanced Binary Tree

Description:
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Difficulty rating: Medium

Notes: The trick is to orchestrate the order of traversal properly so that no node is visited more than once, maintaining O(n) complexity.

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
  bool isBalancedWithDepth(TreeNode *root, int& depth) {
    if (!root) {
      depth = 0;
      return true;
    }
    int depth_l, depth_r;
    bool res = isBalancedWithDepth(root->left, depth_l);
    if (!res) return false; 
    res &= isBalancedWithDepth(root->right, depth_r);
    depth = max(depth_l, depth_r) + 1;
    return res && (abs(depth_l - depth_r) <= 1);
  }
  bool isBalanced(TreeNode *root) {
    int depth;
    return isBalancedWithDepth(root, depth);
  }
};
