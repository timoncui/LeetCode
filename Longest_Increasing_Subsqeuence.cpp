/*
Author: Timon Cui, timonbaby@163.com

Title: Longest Increasing Subsequence

Description:
Given a list of numbers A output the length of the longest increasing subsequence. 
An increasing subsequence is defined as a set {i0 , i1 , i2 , i3 , ... , ik} 
such that 0 <= i0 < i1 < i2 < i3 < ... < ik < N 
and A[ i0 ] < A[ i1 ] < A[ i2 ] < ... < A[ ik ]. 
A longest increasing subsequence is a subsequence with the maximum k (length).

i.e. in the list {33 , 11 , 22 , 44}

the subsequence {33 , 44} and {11} are increasing subsequences 
while {11 , 22 , 44} is the longest increasing subsequence.

Difficulty rating: Medium

Source:
https://www.spoj.pl/problems/ELIS/

Notes:
O(NlogM) solution where N is the length of the list and M is the length of the longest increasing subsequence:

Sweep the list,
maintain a list M where M[L - 1] is the index of the smallest tail of the current longest sequence of length L.
Then for each i, we try to append x[i] to the end of sequences of the longest length.
Because x[M[m]] > x[M[n]] if m > n, this can be done using binary search.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Greater {
  bool operator()(const int a, const int b) { return x[a] > x[b]; }
  static vector<int> x;
};
vector<int> Greater::x;

int longestIncreasingSubsequence(const vector<int>& x) {
  Greater::x = x;  
  vector<int> M; // M[L - 1] contains index of the smallest tail of a sequence of length L
  for (int i = 0; i < x.size(); ++i) {
    int L = M.rend() - upper_bound(M.rbegin(), M.rend(), i, Greater()) + 1; // Length ending here
    if (L <= M.size()) {
      if (x[i] < x[M[L - 1]]) M[L - 1] = i;
    } else {
      M.push_back(i);
    }
  }
  return M.size();
}

int longestIncreasingSubsequence1(const vector<int>& x) {
  vector<int> M(1, -1);
  for (int i = 0; i < x.size(); ++i) {
    for (int L = M.size() - 1; L >= 0; --L) {
      if (L == 0 || x[i] > x[M[L]]) { // Can append                                                                                                                               
        int new_L = L + 1;
        if (new_L < M.size()) {
          if (x[i] < x[M[new_L]]) M[new_L] = i;
        } else {
          M.push_back(i);
        }
        break;
      }
    }
  }
  return M.size() - 1;
}

int main() {
  int N;
  cin >> N;
  vector<int> x(N);
  for (int i = 0; i < N; ++i) cin >> x[i];
  cout << longestIncreasingSubsequence(x);
}
