/*
Author: Timon Cui, timonbaby@163.com

Title: Recover Binary Search Tree

Description:
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
In order traversal of a BST should be increasing.
Due to swap of A[i] and A[j], this is no longer true.

E. g. 1 2 3 4 5 --> 1 4 3 2 5
or 1 2 3 4 --> 1 3 2 4

Assume i < j, then A[j] can be found because A[j + 1] < A[j].
A[i] can be found because A[i] < A[i - 1], unless j = i + 1 (second example),
in which case only one such inversion place can be found.

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

#include "algorithm.hpp"

class Solution {
public:
  void recoverTree(TreeNode *root) {
    TreeNode *error[2] = {NULL};
    TreeNode *pre = NULL;
    findInvalid(root, pre, error);
    swap(error[0]->val, error[1]->val);
  }
private:
  void findInvalid(TreeNode *root, TreeNode *&pre, TreeNode *error[2]) {  
    if (!root) return;
    findInvalid(root->left, pre, error);
    if (pre && root->val < pre->val) {
      if (!error[1]) error[0] = pre;
      error[1] = root;
    }
    pre = root;
    findInvalid(root->right, pre, error);
  }
};
