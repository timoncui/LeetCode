/*
Author: Timon Cui, timonbaby@163.com

Title: Flatten Binary Tree to Linked List

Description:
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Difficulty rating: Medium

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

#include "utils.hpp"
using namespace std;

/* Similar to in order traversal. Keep track of the tail node.
O(n).
*/
class Solution {
public:
  void flatten(TreeNode *root) {
    flatten_keep_tail(root);
  }
private:
  TreeNode *flatten_keep_tail(TreeNode *root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;
    TreeNode *left_tail = flatten_keep_tail(root->left);
    TreeNode *right_tail = flatten_keep_tail(root->right);
    if (left_tail) {
      left_tail->right = root->right;
      root->right = root->left;
      root->left = NULL;    
    }
    return right_tail ? right_tail : left_tail;
  }
};
    
/* Remove right subtree, rotate left subtree to right subtree, append the original
right subtree after the last node in current tree, then go to the next node.

O(nlogn) since each step we need to find the last node in current tree.

48 ms for 225 test cases in JudgeLarge.
*/
class SolutionNlogN {
public:
  void flatten(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *right = root->right;
    root->right = root->left;
    root->left = NULL;
    TreeNode *cur = root;
    while(cur->right) cur = cur->right;
    cur->right = right;
    flatten(root->right);
  }
};
