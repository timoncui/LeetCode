/*
Author: Timon Cui, timonbaby@163.com

Title: Scramble String

Description:

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Difficulty rating:

Notes:

Divide and conquer, O(n^2).

32 ms for 281 test cases on JudgeLarge.

*/

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (!isAnagram(s1, s2)) return false;
    if (s1.length() <= 3) return true;
    for (int left = 1; left < s1.size(); ++left) {
      if (isScramble(s1.substr(0, left), s2.substr(0, left)) &&
	  isScramble(s1.substr(left, s1.length()), s2.substr(left, s2.length()))) 
	return true;
      if (isScramble(s1.substr(0, left), s2.substr(s2.length() - left, left)) && 
	  isScramble(s1.substr(left, s1.length()), s2.substr(0, s2.length() - left)))
	return true;
    }
    return false;
  }
private:
  bool isAnagram(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;
    vector<int> N(26, 0);
    for (int i = 0; i < s1.size(); ++i) N[s1[i] - 'a'] ++;
    for (int i = 0; i < s2.size(); ++i) {
      if (N[s2[i] - 'a'] -- == 0) return false;
    }
    return true;
  }
};
