/*
Author: Timon Cui, timonbaby@163.com

Title: Merge K Sorted Lists

Description:
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Difficulty rating:

Notes:
O(nlogk) when k << n.

80 ms for 129 test cases in JudgeLarge.
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
  static bool Compare(const ListNode *a, const ListNode *b) {
    return a->val > b->val;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *root = NULL, *tail = NULL;
    vector<ListNode*> H;
    for (int i = 0; i < lists.size(); ++i) if (lists[i]) H.push_back(lists[i]);
    make_heap(H.begin(), H.end(), Compare);
    while (H.size()) {
      pop_heap(H.begin(), H.end(), Compare);
      ListNode *n = H.back();
      H.pop_back();
      if (tail) {
	tail->next = n;
	tail = n;
      } else {
	root = n;
	tail = n;
      }
      if (n->next) {
	H.push_back(n->next);
	push_heap(H.begin(), H.end(), Compare);
      }
    }
    return root;
  }
};
