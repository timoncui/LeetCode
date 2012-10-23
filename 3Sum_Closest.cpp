/*
Author: Timon Cui, timonbaby@163.com

Title: 3Sum Closest

Description:
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Difficulty rating:

Notes: 
O(n^2), similar to the 3Sum problem.

With large numbers as input, the code may overflow. Not handled here for simplicity.
For example, when sum = INT_MAX and target = INT_MIN, sum - target will overflow.

*/

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int closest_sum = 0, distance = -1;
    for (int i = 0; i < num.size() - 2; ++i) {
      int L = i + 1, H = num.size() - 1;
      while (L < H) {
	int sum = num[i] + num[L] + num[H];
	if (sum > target) H --;
	else if (sum < target) L ++;
	else return target;
	if (distance < 0 || abs(sum - target) < distance) {
	  closest_sum = sum;
	  distance = abs(sum - target);
	}
      }
    }
    return closest_sum;
  }
};
