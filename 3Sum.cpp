/*
Author: Timon Cui, timonbaby@163.com

Title: 3Sum

Description:
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Difficulty rating: Medium

Source:
http://www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html

Notes:

O(n^2). 280 ms for 311 test cases in JudgeLarge.
The twoSumSorted() function is O(n). Note how to avoid duplicate results using the two while loops in the inner loop.

*/
class Solution {
public:
  vector<vector<int> > twoSumSorted(const vector<int>& v, int L, int H, int S) {
    vector<vector<int> > result;
    while (L < H) {
      int sum = v[L] + v[H];
      if (sum > S) H --;
      else if (sum < S) L ++;
      else {
	int p[] = {v[L], v[H]};
	result.push_back(vector<int>(p, p + 2));
	while (L < v.size() && v[L] == p[0]) L ++;
	while (H >= 0 && v[H] == p[1]) H --;
      }
    }
    return result;
  }
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > result;
    for (int i = 0; i < num.size(); ++i) {
      if (i > 0 && num[i] == num[i - 1]) continue;
      vector<vector<int> > p = twoSumSorted(num, i + 1, num.size() - 1, -num[i]);
      for (int j = 0; j < p.size(); ++j) {
	p[j].insert(p[j].begin(), num[i]);
	result.push_back(p[j]);
      }
    }
    return result;
  }
};
