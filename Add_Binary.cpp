/*
Author: Timon Cui, timonbaby@163.com

Title: Add Binary

Description:
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".

Difficulty rating: Easy

Notes: Could convert to unit, perform addition, then convert back, but won't be able to handle long inputs.
*/

class Solution {
public:
  int MakeFirstLonger(string& a, string& b) {
    if (a.length() < b.length()) swap(a, b);
    return a.length() - b.length();
  }
  string And(string a, string b) {
    int offset = MakeFirstLonger(a, b);
    string c = b;
    for (int i = 0; i < b.length(); ++i) {
      if (a[i + offset] == '0') c[i] = '0';
    }
    return c;
  }
  string Xor(string a, string b) {
    int offset = MakeFirstLonger(a, b);
    string c = a;
    for (int i = 0; i < b.length(); ++i) {
      c[i + offset] = a[i + offset] != b[i] ? '1' : '0';
    }
    return c;
  }
  string addBinary(string a, string b) {
    string c = And(a, b), s = Xor(a, b);
    while (c.find('1') != string::npos) {
      string t = c.substr(c.find('1'), c.length()) + "0";
      c = And(s, t);
      s = Xor(s, t);
    }
    return s;
  }
};
