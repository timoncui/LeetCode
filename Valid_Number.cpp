/*
Author: Timon Cui, timonbaby@163.com

Title: Valid Number

Description:
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Difficulty rating: Easy

Notes: This problem should be solved using proper grammar logic. 
The solution below is ad hoc and should not be used in real applications.

*/

class Solution {
public:
  bool isNumber(const char *cs) {
    string s(cs);
    if (s.length() == 0) return false;

    // Strip leading and trailing spaces
    int from = 0, to = s.length() - 1;
    while (from < s.length() && s[from] == ' ') from ++;
    while (to >= 0 && s[to] == ' ') to --;
    s = s.substr(from, max(0, to - from + 1));

    int p = s.find('e');
    string e = "";
    if (p != string::npos) {
      e = s.substr(p + 1, s.length());
      s = s.substr(0, p);
      if (e == "") return false;
    }

    bool res = true;
    if (e.length()) res &= isInt(e);
    res &= isNumberNoE(s);
    return res;
  }
  bool isNumberNoE(string s) {
    if (s == "") return false;
    if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
    int p = s.find('.');
    string dec = "";
    if (p != string::npos) {
      dec = s.substr(p + 1, s.length());
      s = s.substr(0, p);
    }
    bool res = s.length() || dec.length();
    if (s.length()) res &= isIntNoSign(s);
    if (dec.length()) res &= isIntNoSign(dec);
    return res;
  }
  bool isIntNoSign(string s) {
    if (s.length() == 0) return false;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] > '9' || s[i] < '0') return false;
    }
    return true;
  }
  bool isInt(string s) {
    if (s == "") return false;
    if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
    return isIntNoSign(s);
  }
};
