/*
Author: Timon Cui, timonbaby@163.com

Title: Median of Two Sorted Arrays

Description:
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
O(log(m + n)).
180 ms for 2078 test cases in JudgeLarge.

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2 == 1) return kth_element(A, m, B, n, (m + n) / 2);
    else return (kth_element(A, m, B, n, (m + n) / 2) + kth_element(A, m, B, n, (m + n) / 2 - 1)) / 2;
  }
private:
  double kth_element(int *A, int m, int *B, int n, int k) {
    if (m == 0) return B[k];
    if (n == 0) return A[k];
    int rank_a = min(k / 2, m - 1);
    int rank_b = upper_bound(B, B + n, A[rank_a]) - B;
    if (rank_a + rank_b == k) return A[rank_a];
    else if (rank_a + rank_b > k) return kth_element(A, rank_a, B, rank_b, k);
    else return kth_element(A + rank_a + 1, m - rank_a - 1, B + rank_b, n - rank_b, k - rank_a - rank_b - 1);
  }
};

int main() {
  Solution s;
  {
    int A[] = {2, 2, 4, 5};
    int B[] = {1, 2, 2, 3, 3, 4, 55, 66, 77, 99, 991, 992, 993, 999, 10000, 10001};
    eq(0, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 30.0);
  }
  {
    int A[] = {};
    int B[] = {1, 2, 3, 4, 5};
    eq(1, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 3.0);
  }
  {
    int A[] = {5, 6, 7, 8};
    int B[] = {5, 6, 7, 8};
    eq(2, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 6.5);
  }
  {
    int A[] = {-1, 3, 4};
    int B[] = {-5};
    eq(3, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 1.0);
  }
  {
    int A[] = {-2, 0, 0, 0, 0, 5, 50};
    int B[] = {51, 52, 53, 54, 55};
    eq(4, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 27.5);
  }
  return 0;
}
