/*
Author: Timon Cui, timonbaby@163.com

Title: String Reduction

Description:
Given a string consisting of a,b and c's, we can perform the following operation: 
Take any two adjacent distinct characters and replace it with the third character. 
For example, if 'a' and 'c' are adjacent, they can replaced with 'b'. 
What is the smallest string which can result by applying this operation repeatedly?

Difficulty rating: Hard

Source:
https://www.interviewstreet.com/challenges/dashboard/#problem/4f6522ab2f425

Notes:
Key observations:
1. An ireduciable string must contain only one kind of character, either only 'a', only 'b', or only 'c'.
2. Use DP similar to the matrix chain multiplication problem. Keep track of the optimal result for each section.

Proof of optimality is not straightforward.

When merging two strings each containing only one kind of character, follow the rules below:
If two strings contain the same character, concatenate them. (aa + aaa = aaaaa)
Otherwise,
If lengths of both strings are odd, can produce a string of length 1 containing the third character. (aaa + bbb = c)
Otherwise,
If only one length is odd, can produce a string of length 1 containing the character in that string. (aaa + bb = a)
Otherwise,
Since both lengths are even, can produce either of the strings. (aaaa + bb = aaaa or bb)
We choose the shorter one.

*/

#include "utils.hpp"
using namespace std;

pair<int, char> merge(char a, int na, char b, int nb) {
  if (a == b) return make_pair(na + nb, a);
  if (na % 2 == 1 && nb % 2 == 1) return make_pair(1, 'a' + 'b' + 'c' - a - b);
  if (na % 2 == 1) return make_pair(1, a);
  if (nb % 2 == 1) return make_pair(1, b);
  if (na < nb) return make_pair(na, a);
  return make_pair(nb, b);
}

int shortestReduction(const string& x) {
  int L = x.size();
  vector<vector<pair<int, char> > > N(L, vector<pair<int, char> >(L, make_pair(INT_MAX, 'd')));
  for (int i = 0; i < L; ++i) {
    N[i][i] = make_pair(1, x[i]);
  }
  for (int diff = 1; diff < L; ++diff) {
    for (int i = 0; i < L - diff; ++i) {
      int j = i + diff;
      for (int k = i; k < j; ++k) {
	// Merge [i, k] and [k + 1, j]
	pair<int, char> res = merge(N[i][k].second, N[i][k].first, N[k + 1][j].second, N[k + 1][j].first);
	if (res.first < N[i][j].first) N[i][j] = res;
      }
    }
  }
  return N[0][L - 1].first;
}

int main() {
  int N = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string x;
    cin >> x;
    cout << shortestReduction(x) << endl;
  }
}
