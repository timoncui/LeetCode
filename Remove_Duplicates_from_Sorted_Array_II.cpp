/*
Author: Timon Cui, timonbaby@163.com

Title: Remove Duplicates from Sorted Array II

Description:
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3].

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int write = 1, repeat = 0;
        for (int read = 1; read < n; ++read) {
            if (A[read] == A[write - 1]) {
                if (++repeat >= 2) continue;
            } else repeat = 0;
            A[write++] = A[read];
        }
        return write;
    }
};