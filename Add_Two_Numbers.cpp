/*
Author: Timon Cui, timonbaby@163.com

Title: Add Two Numbers

Description:
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
  ListNode *addTwoNumbers(ListNode *L1, ListNode *L2) {
    ListNode *sum = NULL, *tail = NULL;
    int c = 0;
    while (L1 || L2) {
      if (L1 == NULL) swap(L1, L2);
      int s = c + L1->val + (L2 ? L2->val : 0);
      if (tail) {
	tail->next = new ListNode(s % 10);
	tail = tail->next;
      } else {
	sum = new ListNode(s % 10);
	tail = sum;
      }
      c = s / 10;
      L1 = L1->next;
      if (L2) L2 = L2->next;
    }
    if (c) {
      tail->next = new ListNode(c);
    }
    return sum;
  }
};
