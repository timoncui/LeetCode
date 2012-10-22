/*
Author: Timon Cui, timonbaby@163.com

Title: ZigZag Conversion

Description:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows.

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows <= 1) return s;
    int N = s.length();
    string t(N, ' ');
    int i = 0;
    for (int r = 0; r < nRows; ++r) {
      for (int j = 0; j < N + nRows - 2; j += 2 * nRows - 2) {
	for (int sign = (r == 0 || r == nRows - 1) ? 1 : -1; 
	     sign <= 1; 
	     sign += 2) {
	  int pos = j + sign * r;
	  if (pos >= 0 && pos < N) t[i++] = s[pos];
	}
      }	
    }
    return t;              
  }
};
