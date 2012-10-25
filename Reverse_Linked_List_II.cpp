/*
Author: Timon Cui, timonbaby@163.com

Title: Reverse Linked List II

Description:
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.

Difficulty rating:

Notes:
A small trick is to append a dummy node in front of the true head 
so that the special case when the range contains the true head
doesn't need to be handled.

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
  // Prepend a dummy node so the reversed range won't contain head node of the new list
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    reverseBetweenNotContainingHead(&dummy, m + 1, n + 1);
    return dummy.next;
  }
  void reverseBetweenNotContainingHead(ListNode *head, int m, int n) {
    n -= m; // n now contains length of region - 1
    while (m -- > 2) head = head->next;
    ListNode *start = head->next, *pre = head->next, *cur = pre->next;
    while (n --) {
      ListNode *cur_next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = cur_next;
    }
    head->next = pre; // Append to the part of list before the reversed ange
    start->next = cur; // Connect to rest of the list
  }
};
