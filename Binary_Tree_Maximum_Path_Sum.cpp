/*
Author: Timon Cui, timonbaby@163.com

Title: Binary Tree Maximum Path Sum

Description:
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
Post order traverse, keep track of max sum on left and right.
Similar to max subarray problem.
https://github.com/timoncui/LeetCode/blob/master/Maximum_Subarray.cpp

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
  int maxPathSum(TreeNode *root) {
    int dummy;
    return maxPathSum(root, &dummy);
  }
private:
  int pos(int v) { return v > 0 ? v : 0; }
  int maxPathSum(TreeNode *root, int *max_ending_here) {
    if (root == NULL) {
      *max_ending_here = INT_MIN;
      return INT_MIN;
    }
    int max_ending_left, max_ending_right;
    int max_left = maxPathSum(root->left, &max_ending_left);
    int max_right = maxPathSum(root->right, &max_ending_right);
    *max_ending_here = root->val + pos(max(max_ending_left, max_ending_right));
    return max(max(max_left, max_right), root->val + pos(max_ending_left) + pos(max_ending_right));
  }
};
