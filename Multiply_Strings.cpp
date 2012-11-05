/*
Author: Timon Cui, timonbaby@163.com

Title: Multiply Strings

Description:
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:

*/
class Solution {
public:
  string multiply(string num1, string num2) {
    string res = "0";
    for (int i = 0; i < num1.size(); ++i) {
      res = add(res, multiply(num1[i] - '0', num1.size() - i - 1, num2));
    }
    // Remove prefix 0
    int i = 0;
    while (i < res.size() && res[i] == '0') i ++;
    res = res.substr(i, res.size());
    return res.size() ? res : "0";
  }
private:
  string multiply(int v, int k, const string& x) {
    int carry = 0;
    string p(x.size(), '0');
    for (int i = x.size() -1; i >= 0; --i) {
      int sum = carry + v * (x[i] - '0');
      p[i] = (sum % 10) + '0';
      carry = sum / 10;
    }
    if (carry) p = string(1, carry + '0') + p;
    return p + string(k, '0');
  }
  string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    string s(a.size(), '0');
    int carry = 0, offset = a.size() - b.size();
    for (int i = a.size() - 1; i >= 0; --i) {
      int sum = carry + a[i] - '0' + (i >= offset ? b[i - offset] - '0' : 0);
      s[i] = (sum % 10) + '0';
      carry = sum / 10;
    }
    if (carry) s = string(1, carry + '0') + s;
    return s;
  }
};
