/*
Author: Timon Cui, timonbaby@163.com

Title: Search in Rotated Sorted Array

Description:

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Difficulty rating:

Notes:

Small modification of binary search.
There are two cases depending on whether the gap is on the left or right side of the middle pointer:

           L   M    R

                 +
                +         A[M] too small --> [M + 1, R]
               +          A[M] too large --> A[L] too large --> [M + 1, R]
              +                                        Else --> [L, M - 1]
Case 1       +
            +
           +
                    +
                   +
                  +


             +
            +
           +        +
                   +      A[M] too small --> A[R] too small --> [L, M - 1]
                  +                                    Else --> [M + 1, R]
Case 2           +
                +         A[M] too large --> [L, M - 1]
               +
              +
*/


class Solution {
public:
  int search(int A[], int n, int target) {
    int L = 0, R = n - 1;
    while (L <= R) {
      int M = (L + R) / 2;
      if (A[M] == target) return M;
      if (A[M] < target) {
	if (A[M] < A[L] && A[R] < target) R = M - 1;
	else L = M + 1;
      } else {
	if (A[M] > A[R] && A[L] > target) L = M + 1;
	else R = M - 1;
      }
    }
    return -1;
  }
};
