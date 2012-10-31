/*
Author: Timon Cui, timonbaby@163.com

Title: First Missing Positive

Description:
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:

Solution1: O(n)
1. Do a partition operation put all positive numbers in front.
2. For each possitive number i in the range, mark A[i - 1] as negative if i is in range.
3. Scan and find the first i where A[i - 1] is positive.

Better yet, observe that the largest possible missing possitive number is n + 1.
So if whenever we see v, we put it at A[v - 1], then we can scan A to see what is missing.
This is Solution, and also O(n).

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    // for v in [1, n], put it at A[v - 1]
    int i = 0;
    while (i < n) {
      int v = A[i];
      if (1 <= v && v <= n && A[v - 1] != v) {
	swap(A[i], A[v - 1]);
	continue;
      }
      i ++;
    }
    // Check to find the first place where A[v - 1] != v
    int v = 1;
    while (A[v - 1] == v) v ++;
    return v;
  }
};

class Solution1 {
public:
  int firstMissingPositive(int A[], int n) {
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i] > 0) A[m ++] = A[i];
    }
    for (int i = 0; i < m; ++i) {
      int v = abs(A[i]);
      if (v <= m) A[v - 1] = min(A[v - 1], -A[v - 1]);
    }
    for (int i = 0; i < m; ++i) {
      if (A[i] > 0) return i + 1;
    }
    return m + 1;
  }
};


int main() {  
  Solution s;
  {
    int A[] = {1, -2, 5, 4, 2, 3, 7, 66, 6, 9999, -2, 0, 6, -10, 100, -200};
    eq(0, 8, s.firstMissingPositive(A, ARRAYSIZE(A)));
  }
  {
    int A[] = {5, 4, 3, 2, 1, 6, 7};
    eq(1, 8, s.firstMissingPositive(A, ARRAYSIZE(A)));
  }
  {
    int A[] = {};
    eq(2, 1, s.firstMissingPositive(A, ARRAYSIZE(A)));
  }
  {
    int A[] = {1};
    eq(3, 2, s.firstMissingPositive(A, ARRAYSIZE(A)));
  }
}
