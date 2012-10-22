/*
Author: Timon Cui, timonbaby@163.com

Title: Valid Parentheses

Description: 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Difficulty rating: Easy

Notes:

*/


class Solution {
public:
  bool isValid(string s) {
    string L = "{[(", R = "}])";
    stack<char> S;
    for (int i = 0; i < s.length(); ++i) {
      if (L.find(s[i]) != string::npos) S.push(s[i]);
      else if (S.empty() || L.find(S.top()) != R.find(s[i])) return false;
      else S.pop();
    }
    return S.empty();
  }
};
