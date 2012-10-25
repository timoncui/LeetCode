/*
Author: Timon Cui, timonbaby@163.com

Title: Merge K Sorted Lists

Description:
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Difficulty rating:

Notes:
O(nlogk) when k << n, the total number of nodes.

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *root = NULL, *tail = NULL;
    priority_queue<ListNode *, vector<ListNode *>, Compare> Q;
    for (int i = 0; i < lists.size(); ++i) if (lists[i]) Q.push(lists[i]);
    while (!Q.empty()) {
      ListNode *n = Q.top();
      Q.pop();
      if (tail) {
	tail->next = n;
	tail = n;
      } else {
	root = n;
	tail = n;
      }
      if (n->next) Q.push(n->next);
    }
    return root;
  }
private:
  struct Compare {
    bool operator()(const ListNode *a, const ListNode *b) { return a->val > b->val; }
  };
};
