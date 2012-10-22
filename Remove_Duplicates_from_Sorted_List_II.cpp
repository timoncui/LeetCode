/*
Author: Timon Cui, timonbaby@163.com

Title: Remove Duplicates from Sorted List II

Description:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *result = NULL, *write = NULL, *read = head;
        while (read) {
            if (read->next && read->val == read->next->val) {
                int val = read->val;
                while (read && read->val == val) {
                    ListNode *read_next = read->next;
                    delete read;
                    read = read_next;
                }
            } else {
                if (write) {
                    write->next = read;
                    write = write->next;
                } else {
                    result = read;
                    write = read;
                }
                read = read->next;
                write->next = NULL;
            }
        }
        return result;
    }
};
