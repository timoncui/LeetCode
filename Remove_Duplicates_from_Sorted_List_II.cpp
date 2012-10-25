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
        ListNode *result = NULL, *tail = NULL, *read = head;
        while (read) {
            if (read->next && read->val == read->next->val) {
                int val = read->val;
                while (read && read->val == val) {
                    ListNode *read_next = read->next;
                    delete read;
                    read = read_next;
                }
            } else {
	        append(result, tail, read);
            }
        }
        return result;
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
