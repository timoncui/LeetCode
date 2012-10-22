/*
Author: Timon Cui, timonbaby@163.com

Title: 3Sum Closest

Description:
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Difficulty rating:

Notes:

*/

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int closest_sum = INT_MAX;
    for (int i = 0; i < num.size(); ++i) {
      int L = i + 1, H = num.size() - 1;
      while (L < H) {
	int sum = v[i] + v[L] + v[H];
	if (sum > target) H --;
	else if (sum < target) L ++;
	else return target;
	if (abs(sum - target) < abs(closest_sum - target)) closest_sum = sum;
      }
    }
    return closest_sum;
  }
};
