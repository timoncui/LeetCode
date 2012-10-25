/*
Author: Timon Cui, timonbaby@163.com

Title: Remove Nth Node From End of List

Description:
Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Difficulty rating: Easy

Notes:
The key is to have two pointers distance n apart and advance together.
Corner case of deleting the head node need to be handled.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head || n <= 0) return NULL;
    ListNode *parent = head, *cur = head, *tail = head;
    int steps = 0;
    while (tail->next) {
      tail = tail->next;
      if (steps >= n - 1) cur = cur->next;
      if (steps >= n) parent = parent->next;
      steps ++;
    }
    if (steps >= n - 1) {
      if (parent == cur) head = parent->next; // Delete head node
      else parent->next = cur->next;          // Delete middle node
      delete cur;
    }
    return head;
  }
};
