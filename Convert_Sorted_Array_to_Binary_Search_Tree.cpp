/*
Author: Timon Cui, timonbaby@163.com

Title: Convert Sorted Array to Binary Search Tree

Description:
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Difficulty rating:

Source:
http://www.leetcode.com/2010/11/convert-sorted-array-into-balanced.html
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
    return sortedArrayToBST(num, 0, num.size());
  }
private:
  TreeNode *sortedArrayToBST(vector<int>& num, int from, int to) {
    if (from == to) return NULL;
    int mid = from + (to - from) / 2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = sortedArrayToBST(num, from, mid);
    root->right = sortedArrayToBST(num, mid + 1, to);
    return root;
  }
};
