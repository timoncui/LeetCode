/*
Author: Timon Cui, timonbaby@163.com

Title: 4Sum

Description:
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)

Difficulty rating: Medium

Notes:
O(n^3) solution: Fix first two indices (O(n^2)) and solve 2Sum problem (O(n)) for the other two.

O(logn n^2) solution (below): Generate all O(n^2) two sums. Solve two sum problem on the new list.
Complexity is dominated by sorting. Since different pairs may have the same sum, special care
need to be taken to avoid missing correct combinations of pairs.

240 ms for 282 test cases in JudgeLarge.
*/

class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<Pair> pairs;
    for (int i = 0; i < num.size(); ++i)
      for (int j = i + 1; j < num.size(); ++j)
	pairs.push_back(Pair(i, j, num));
    sort(pairs.begin(), pairs.end());
    
    set<vector<int> > result;
    int L = 0, H = pairs.size() - 1;
    while (L < H) {
      int sum = pairs[L].sum + pairs[H].sum;
      if (sum == target) {
	// Since pairs may contain consecutive items with same sum, iterate over all combinations
	int low, high;
	for (low = L; low < H && pairs[low].sum == pairs[L].sum; ++low) {
	  for (high = H; high > L && pairs[high].sum == pairs[H].sum; --high) {
	    if (Pair::Compatible(pairs[low], pairs[high])) {
	      int t[] = {pairs[low].v1, pairs[low].v2, pairs[high].v1, pairs[high].v2};
	      sort(t, t + 4);
	      result.insert(vector<int>(t, t + 4));
	    }
	  }
	}
	L = low;
	H = high;
      } else if (sum < target) {
	L ++;
      } else H --;
    }
    return vector<vector<int> >(result.begin(), result.end());
  }
private:
  class Pair {
  public:
    Pair(int i, int j, const vector<int>& num) : i1(i), v1(num[i]), i2(j), v2(num[j]) {
      sum = v1 + v2;
    }
    static bool Compatible(const Pair& low, const Pair& high) {
      return low.i1 != high.i1 && low.i1 != high.i2 && low.i2 != high.i1 && low.i2 != high.i2;
    }
    bool operator <(const Pair& other) const {
      return sum < other.sum;
    }
    int i1;
    int v1;
    int i2;
    int v2;
    int sum;
  };
};
