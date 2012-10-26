/*
Author: Timon Cui, timonbaby@163.com

Title: Reverse Nodes in k-Group

Description:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Difficulty rating:

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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0);
    ListNode *tail = &dummy, *cur = head;
    while (cur) {
      int n = k - 1;
      ListNode *test = cur;
      while (n -- && test) test = test->next; // Make sure at least k left
      if (test) {
	ListNode *sub_tail = cur, *pre = NULL;
	for (int i = 0; i < k; ++i) {
	  ListNode *next = cur->next;
	  if (pre) cur->next = pre;
	  pre = cur;
	  cur = next;
	}
	tail->next = pre;
	tail = sub_tail;
	tail->next = NULL;
      } else {
	tail->next = cur; // Append the rest
	cur = NULL;
      }
    }
    return dummy.next;
  }
};
