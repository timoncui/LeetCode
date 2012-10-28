/*
Author: Timon Cui, timonbaby@163.com

Title: Rotate List

Description:
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return head;
        
        // Let tail walk k steps
        ListNode *tail = head;
        int L = 0;
        while (tail->next && L < k) {
            tail = tail->next; 
            L ++;
        }
        
        // If reaches the end before k steps, the list has length L + 1
        if (L < k) return rotateRight(head, k % (L + 1));        
        
        // Keep walking parent and tail together till the end
        ListNode *parent = head;
        while (tail->next) {
            tail = tail->next;
            parent = parent->next;
        }
        tail->next = head;
        head = parent->next;
        parent->next = NULL;
        return head;
    }
};