/*
Author: Timon Cui, timonbaby@163.com

Title: Convert Sorted Array to Binary Search Tree

Description:
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Difficulty rating:

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
  TreeNode *sortedArrayToBST(vector<int> &num) {
    if (num.size() == 0) return NULL;
    int m = num.size() / 2;
    TreeNode *root = new TreeNode(num[m]);
    vector<int> left(num.begin(), num.begin() + m), right(num.begin() + m + 1, num.end());
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
  }
};
