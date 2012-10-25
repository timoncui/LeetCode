/*
Author: Timon Cui, timonbaby@163.com

Title: Next Permutation

Description:
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1

Difficulty rating: Medium

Notes:
To generate the next permutation:
1. Scan from right to left until we find first decrease at i
2. Binary search from i + 1 to end the smallest element j that is larger than num[i]
3. Swap i and j
4. Reverse i + 1 to end

If step 1 fails, it means there is no next permutation (the array is sorted in descending order).

*/

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    for (int i = num.size() - 2; i >= 0; --i) {
      if (num[i] < num[i + 1]) {
	int j = num.rend() - 1 - upper_bound(num.rbegin(), num.rend() - i - 1, num[i]);
	swap(num[i], num[j]);
	reverse(num.begin() + i + 1, num.end());
	return;
      }
    }
    reverse(num.begin(), num.end());
  }
};
