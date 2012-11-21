/*
Author: Timon Cui, timonbaby@163.com

Title: Sort Colors

Description:
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 
to represent the color red, white, and blue respectively.

Need one pass algorithm with constant space.

Difficulty rating: Medium

Notes:
This is a special case of the Dutch national flag problem.

*/

class Solution {
public:
  void sortColors(int A[], int n) {
    int i0 = 0, i2 = n - 1, i = 0;
    while (i <= i2) {
      if (A[i] == 0) swap(A[i0 ++], A[i ++]);
      else if (A[i] == 1) i ++;
      else swap(A[i], A[i2 --]);
    }
  }
};
