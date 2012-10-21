/*
Author: Timon Cui, timonbaby@163.com

Title: Jump Game

Description:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
    bool canJump(int A[], int n) {
        int range = 0;
        for (int i = 0; i <= range; ++i) {
            range = max(range, i + A[i]);
            if (range >= n - 1) return true;
        }
        return false;
    }
};
