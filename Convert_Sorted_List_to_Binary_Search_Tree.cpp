/*
Author: Timon Cui, timonbaby@163.com

Title: Convert Sorted List to Binary Search Tree

Description:
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
Bottom up, O(n).
http://www.leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *cur = head;
    int n = 0;
    while (cur) {
      cur = cur->next;
      n ++;
    }
    return sortedListToBST(head, n);
  }
private:
  TreeNode *sortedListToBST(ListNode *&head, int n) {
    if (n == 0) return NULL;
    TreeNode *left = sortedListToBST(head, n / 2);
    TreeNode *root = new TreeNode(head->val);
    root->left = left;
    head = head->next;
    root->right = sortedListToBST(head, n - n / 2 - 1);
    return root;
  }
};
