/*
Author: Timon Cui, timonbaby@163.com

Title: Merge Sorted Array

Description:
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.

Difficulty rating: Easy

Notes:
The key is to observe that there are m + n elements in the merged list,
and if we merge from the back, the unmerged elements in A will never get
overwritten. This is O(m + n) and require O(1) extra space.
*/

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int a = m - 1, b = n - 1, w = m + n - 1;
    while (a >= 0 || b >= 0) {
      if (a >= 0 && (b < 0 || A[a] > B[b])) A[w--] = A[a--];
      else A[w--] = B[b--];
    }	 
  }
};
