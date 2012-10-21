/*
Author: Timon Cui, timonbaby@163.com

Title: Jump Game II

Description:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Difficulty rating: Easy

Notes: Sweep from left to right, equivalent to BFS.
The problem statement inherently means that n >= 1 and the final destination can be reached.

*/

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1) return 0;
        vector<int> steps(n, 0);
        int range = 0;
        for (int i = 0; i < n; ++i) {
            for (int pos = range + 1; pos - i <= A[i]; ++pos) {
                range = pos;
                if (range == n - 1) return steps[i] + 1;
                steps[range] = steps[i] + 1;
            }
        }
    }
};