/*
Author: Timon Cui, timonbaby@163.com

Title: Longest Common Subsequence

Description:
You will be given two lines. The first line will contain the string A, 
the second line will contain the string B. 
Both strings consist of no more than 50000 lowercase Latin letters.
Output the length of the longest common subsequence of strings A and B.

Difficulty rating: Medium

Source:
http://www.spoj.pl/problems/EELCS/ "Easy"
http://www.spoj.pl/problems/LCS0/  "Hard"

Notes:
O(MN) time and O(N) space.
This passes the "Easy" version but fails the "Hard" version due to high time complexity.

More time efficient algorithms exist:
http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=878178

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(const string& a, const string& b) {
  int A = a.size(), B = b.size();
  int L[2][B + 1];
  for (int i = 0; i <= 1; ++i) L[i][0] = 0;
  for (int i = 0; i <= B; ++i) L[0][i] = 0;
  for (int i = 1; i <= A; ++i) {
    int this_i = i % 2, pre_i = this_i ? 0 : 1;
    for (int j = 1; j <= B; ++j) {
      if (a[i - 1] == b[j - 1]) L[this_i][j] = 1 + L[pre_i][j - 1];
      else L[this_i][j] = max(L[pre_i][j], L[this_i][j - 1]);
    }
  }
  return max(L[0][B], L[1][B]);
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << longestCommonSubsequence(a, b);
}
