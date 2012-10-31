/*
Author: Timon Cui, timonbaby@163.com

Title: Integer to Roman

Description:
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:
http://en.wikipedia.org/wiki/Roman_numerals

I    1
V    5
X    10
L    50
C    100
D    500
M    1000

Basic rules:

1. Each digit in a number's Arabic numerals representation should be considered separately.
2. I, X, C, M can be repeated <= 3 times. D, L V can not be repeated.
3. Only smaller value can be subtracted from larger values.
4. I can be subtracted from V, X only. X can be subtracted from L and C only.
   C can be subtracted from D, M only. V, L, D can never be subtracted.

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string c[] = {"IVX", "XLC", "CDM", "MYZ"};
    int index[10][4] = {{-1}, {0, -1}, {0, 0, -1}, {0, 0, 0, -1}, {0, 1, -1}, {1, -1}, {1, 0, -1}, {1, 0, 0, -1}, {1, 0, 0, 0}, {0, 2, -1}};
    string s = "";
    int base = 1000, p = 3;
    while (p >= 0) {
      int digit = num / base;
      num %= base;
      base /= 10;
      for (int i = 0; i < 4; ++i) {
	if (index[digit][i] < 0) break;
	s += c[p][index[digit][i]];
      }
      p --;
    }
    return s;
  }
};

int main() {
  Solution s;
  int x[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 42, 92, 109, 388, 593, 999, 1020, 2012, 3999};
  for (int i = 0; i < ARRARYSIZE(x); ++i) cout << "case " << i << ": " << x[i] << " = " << s.intToRoman(x[i]) << endl;
}
