/*
Author: Timon Cui, timonbaby@163.com

Title: Search in Rotated Sorted Array

Description:

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Difficulty rating: Medium

Notes:

Small modification of binary search.
Based on comparison of A[M] and A[L]:
A[M] > A[L]: Left side sorted, in range [A[L], A[M]]
A[M] < A[L]: Right side sorted, in rnage [A[M], A[R]]
otherwise, have to search both part. (This won't happen if no duplicates are allowed.)

*/

class Solution {
public:
  int search(int A[], int n, int target) {
    return search(A, 0, n - 1, target);
  }
private:
  int search(int *A, int L, int R, int target) {
    while (L <= R) {
      int M = (L + R) / 2;
      if (A[M] == target) return M;
      if (A[M] > A[L]) { // Left part sorted
	if (A[L] <= target && target < A[M]) R = M - 1;
	else L = M + 1;
      } else if (A[M] < A[L]) { // Right part sorted
	if (A[M] < target && target <= A[R]) L = M + 1;
	else R = M - 1;
      } else { // A[M] == A[L], need to search both sides
	return max(search(A, L, M - 1, target), search(A, M + 1, R, target));
      }
    }
    return -1;
  }
};
