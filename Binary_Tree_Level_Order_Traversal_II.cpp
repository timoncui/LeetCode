/*
Author: Timon Cui, timonbaby@163.com

Title: Binary_Tree_Level_Order_Traversal_II

Description:
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]

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
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    queue<TreeNode*> Q[2];
    vector<int> one_level;
    int level = 0;
    if (root) Q[0].push(root);
    while (!Q[level].empty()) {
      TreeNode *n = Q[level].front();
      one_level.push_back(n->val);
      Q[level].pop();
      if (n->left) Q[!level].push(n->left);
      if (n->right) Q[!level].push(n->right);
      if (Q[level].empty()) {
	res.push_back(one_level);
	one_level.clear();
	level = !level;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
