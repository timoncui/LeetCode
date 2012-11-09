/*
Author: Timon Cui, timonbaby@163.com

Title: Median of Two Sorted Arrays

Description:
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

Difficulty rating: Hard

Source:
http://www.leetcode.com/2011/03/median-of-two-sorted-arrays.html
http://www.leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
http://www.leetcode.com/onlinejudge

Notes:

Binary search, O(logm + logn):

Use kth_element function for two sorted arrays.
First we assume k-th smallest element is in A.

For an element A[i], we look at B[j] where j = k - i.

If B[j - 1] <= A[i] <= B[j], we know there are exactly k elements <= A[i], so A[i] is the k-th element.
Otherwise, if A[i] > B[j], we know k-th element must appear before i.
Otherwise, if A[i] < B[j - 1], we know k-th element must appear after i.
If binary search fails, we know the k-th element is in B,
so another round of binary search in B would solve the problem.

188 ms for 2078 test cases in JudgeLarge.

*Other methods:

**Not-so-smart binary search, O(log^2(m + n)):

Randomly pick an element A[i], find its rank j in B using binary search.
If i + j = k, we have found the solution.
If i + j > k, we know k-th element cannot appear after i or j.
If i + j < k, we know k-th element can only appear after i and j.

180 ms for 2078 test cases in JudgeLarge.

**Pad and compare medians, O(log(max(m, n))):

Pad -inf and inf to two sides of the shorter array so that they have equal size.
For each iteration, find median of each array and compare,
get rid of lower half of one array and higher half of the other based on comparison results.

**Merge, O(m + n):
Merge the two arrays until the (m + n) / 2 th element appears.

References:
http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf
http://www.leetcode.com/2011/03/median-of-two-sorted-arrays.html
http://www.leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int k = min(m, n) + (max(m, n) - min(m, n)) / 2; // equal to (m + n) / 2 but avoid overflow
    if ((m + n) % 2 == 1) return kth_element(A, m, B, n, k, 0, m - 1);
    else return (kth_element(A, m, B, n, k, 0, m - 1) + kth_element(A, m, B, n, k - 1, 0, m - 1)) / 2;
  }
private:
  double kth_element(int *A, int m, int *B, int n, int k, int left, int right) {
    if (left > right) return kth_element(B, n, A, m, k, 0, n);
    int i = left + (right - left) / 2, j = k - i;
    if (j < 0) return kth_element(A, m, B, n, k, left, i - 1);
    if (j > n) return kth_element(A, m, B, n, k, i + 1, right);
    if ((j == n || A[i] <= B[j]) && (j == 0 || B[j - 1] <= A[i])) return A[i];
    if (j != n && A[i] > B[j]) return kth_element(A, m, B, n, k, left, i - 1);
    if (j != 0 && A[i] < B[j - 1]) return kth_element(A, m, B, n, k, i + 1, right);
  }
};

class SolutionNotSoSmartBinarySearch {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int k = min(m, n) + (max(m, n) - min(m, n)) / 2; // equal to (m + n) / 2 but avoid overflow
    if ((m + n) % 2 == 1) return kth_element(A, m, B, n, k);
    else return (kth_element(A, m, B, n, k) + kth_element(A, m, B, n, k - 1)) / 2;
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
    // m = 4, n = 6, C[10] = 55, C[9] = 5, median = 30
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
  {
    int A[] = {};
    int B[] = {2, 3};
    eq(5, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 2.5);
  }
  {
    int A[] = {2};
    int B[] = {};
    eq(6, s.findMedianSortedArrays(A, ARRAYSIZE(A), B, ARRAYSIZE(B)), 2.0);
  }
  return 0;
}
