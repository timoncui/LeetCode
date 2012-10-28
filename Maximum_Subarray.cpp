/*
Author: Timon Cui, timonbaby@163.com

Title: Maximum Subarray

Description:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int S[n];
        for (int i = 0; i < n; ++i) S[i] = A[i] + ((i > 0 && S[i - 1] > 0) ? S[i - 1] : 0);
        return *max_element(S, S + n);
    }
};