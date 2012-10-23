/*
Author: Timon Cui, timonbaby@163.com

Title: Longest Palindromic Substring

Description:
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.

Difficulty rating: Hard

Notes:
SolutionOn2:
Start from every possible center location, expand to left and right as far as possible.
Worst case complexity O(n^2).
470 ms for 86 test cases in JudgeLarge.

Solution: O(n)
DP. Still sweep from left to right, but if the current location is covered by
a previously discovered palindrome, we don't need to check any letter until the end
of that palindrome, because the information is already there at the mirrored position
of the current location w.r.t. the center of that palindrome.
In this way, each letter is successfully matched with at most one other letter, 
so O(n) matches. The number of mismatches equals to the number of sweep positions,
because each sweep location ends with one and only one mismatch. There are n sweep locations,
making O(n) mismatches. The overall complexity is O(n).

30 ms for 86 test cases in JudgeLarge.

This is called "Manacher's Algorithm":
http://www.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

*/

class Solution {
public:
  string longestPalindrome(string s) {
    string x(2 * s.length() + 1, '#');
    for (int i = 0; i < s.length(); ++i) x[i * 2 + 1] = s[i];
    
    int N = x.length();
    vector<int> M(N, 0); // M[i] = valid # of moves to left and right at i
    // C is the enter of the palindrome that ends furthest down the line of sweeping
    for (int i = 0, C = 0; i < N; ++i) {
      int m = C + M[C] > i ? min(M[C] + C - i, M[2 * C - i]) : 0; 
      // Can move at least m steps, try to expand further
      if (m >= M[C] + C - i) {
	while (i - m - 1 >= 0 && i + m + 1 < N && x[i - m - 1] == x[i + m + 1]) m ++;
	M[i] = m;
	C = i;
      }
    }
    int i = max_element(M.begin(), M.end()) - M.begin();
    return s.substr((i - M[i]) / 2, M[i]);      
  }
};

class SolutionOn2 {
public:
  string longestPalindrome(string s) {
    string x(2 * s.length() + 1, '#');
    for (int i = 0; i < s.length(); ++i) x[i * 2 + 1] = s[i];
    int max_length = 0, pos = 0;
    for (int i = 0; i < x.length(); ++i) {
      int len = 1;
      while (i - len >= 0 && i + len < x.length() && x[i - len] == x[i + len]) len ++;
      len --;
      if (len > max_length) {
	max_length = len;
	pos = i;
      }
    }
    return s.substr((pos - max_length) / 2, max_length);
  }
};
