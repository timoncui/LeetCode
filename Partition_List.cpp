/*
Author: Timon Cui, timonbaby@163.com

Title: Partition List

Description:
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Difficulty rating: Easy

Notes:

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
  ListNode *partition(ListNode *head, int x) {
    ListNode *new_head[2] = {NULL}, *tail[2] = {NULL};
    while (head) {
      int list_index = head->val < x ? 0 : 1;
      append(new_head[list_index], tail[list_index], head);
    }
    append(new_head[0], tail[0], new_head[1], false);
    return new_head[0];
  }
private:
  static void append(ListNode *&head, ListNode *&tail, ListNode *&node, bool cut_off = true) {
    if (node == NULL) return;
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    node = node->next;
    if (cut_off) tail->next = NULL;
  }
};
