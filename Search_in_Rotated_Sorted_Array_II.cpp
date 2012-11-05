/*
Author: Timon Cui, timonbaby@163.com

Title: Search in Rotated Sorted Array II

Description:
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.

Difficulty rating: Medium

Notes:
Worst case O(n) because sometimes by comparing target with A[M] we can eliminate only one element.

*/

class Solution {
public:
  bool search(int A[], int n, int target) {
    return search(A, 0, n - 1, target);
  }
private:
  bool search(int *A, int L, int R, int target) {
    while (L <= R) {
      int M = L + (R - L) / 2;
      if (A[M] == target) return true;
      if (A[M] > A[L]) { // Left part sorted
	if (A[L] <= target && target <= A[M]) R = M - 1;
	else L = M + 1;
      } else if (A[M] < A[L]) { // Right part sorted
	if (A[M] <= target && target <= A[R]) L = M + 1;
	else R = M - 1;
      } else return search(A, L, M - 1, target) || search(A, M + 1, R, target);
    }
    return false;
  }
};
