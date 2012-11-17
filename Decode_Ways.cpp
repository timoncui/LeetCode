/*
Author: Timon Cui, timonbaby@163.com

Title: Decode Ways

Description:
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Difficulty rating:

Source:

Notes:

*/

class Solution {
public:
  int numDecodings(string s) {
    if (s.size() == 0) return 0;
    int n1 = 1, n2 = 1;
    int i = s.size() - 1;
    while (i >= 0) {
      int n = 0;
      if (s[i] <= '9' && s[i] >= '1') n += n1;
      if (i < s.size() - 1) {
	int v = (s[i] - '0') * 10 + s[i + 1] - '0';
	if (10 <= v && v <= 26) n += n2;
      }
      n2 = n1;
      n1 = n;
      i --;
    }
    return n1;        
  }
};
