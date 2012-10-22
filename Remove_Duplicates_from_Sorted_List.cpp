/*
Author: Timon Cui, timonbaby@163.com

Title: Remove Duplicates from Sorted List

Description:
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Difficulty rating: Easy

Notes:
Careful about details:
1. Release memory for skipped nodes.
2. Make sure the last node of the resulting list does not point to anything.

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *write = head, *read = head->next;
        write->next = NULL;
        while (read) {
            ListNode *next_read = read->next;
            if (read->val != write->val) {
                write->next = read;
                write = write->next;
                write->next = NULL;
            } else {
                delete read;
            }
            read = next_read;
        }
        return head;
    }
};
