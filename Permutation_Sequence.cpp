/*
Author: Timon Cui, timonbaby@163.com

Title: Permutation Sequence

Description:
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
http://en.wikipedia.org/wiki/Lehmer_code

O(n^2)

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    k --;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) {
      v[n - i] = k % i;
      k /= i;
    }
    vector<char> c(n);
    for (int i = 0; i < n; ++i) c[i] = i + '1';
    string s(n, '0');
    for (int i = 0; i < n; ++i) {
      s[i] = c[v[i]];
      c.erase(c.begin() + v[i]);
    }
    return s;
  }
};

int main() {
  Solution s;
  eq(0, s.getPermutation(4, 7), "2134");
  eq(1, s.getPermutation(9, 155915), "489523716");
}
