/*
Author: Timon Cui, timonbaby@163.com

Title: 2Sum

Description:

Given an array S of n integers, are there two elements a, b in S such that a + b = 0?

Difficulty rating: Easy

Source:

Notes:

Use a hash table to store all items and their corresponding indices.
For each item x[i], if -x[i] is in the hashtable and its index is not i, we've found a pair.
Here the index checking is only for the special case when x[i] = 0.
Complexity O(n).

If a balanced BST is used for store the numbers, the complexity is O(nlogn).

Can also sort the list, then use two pointer starting from head and tail of the list,
try move inside. O(nlogn). Solution below implements this logic.

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  bool canSumToZero(vector<int> v) {
    sort(v.begin(), v.end());
    int L = 0, R = v.size() - 1;
    while (L < R) {
      int s = v[L] + v[R];
      if (s == 0) return true;
      if (s > 0) R --;
      else L ++;
    }
    return false;
  }
};

int main() {
  Solution s;
  {
    int x[] = {0, 1, 3, 5, 8, -1};
    eq(0, s.canSumToZero(vector<int>(x, x + ARRAYSIZE(x))), true);
  }
  {
    int x[] = {};
    eq(1, s.canSumToZero(vector<int>(x, x + ARRAYSIZE(x))), false);
  }
  {
    int x[] = {0, 1, 3, 5, 8, -2};
    eq(2, s.canSumToZero(vector<int>(x, x + ARRAYSIZE(x))), false);
  }
  {
    int x[] = {10, -10};
    eq(3, s.canSumToZero(vector<int>(x, x + ARRAYSIZE(x))), true);
  }
}
