/*
Author: Timon Cui, timonbaby@163.com

Title: Count and Say

Description:
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:

*/
class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    while (n -- > 1) s = countAndSay(s);
    return s;        
  }
private:
  string countAndSay(const string& s) {
    if (s.size() == 0) return "";
    stringstream ss;
    int c = 1;
    while (c < s.size() && s[c] == s[0]) c ++;
    ss << c << s[0];
    return ss.str() + countAndSay(s.substr(c, s.size()));
  }
};
