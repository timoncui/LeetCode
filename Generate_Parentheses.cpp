/*
Author: Timon Cui, timonbaby@163.com

Title: Generate Parentheses

Description:
Given n pairs of parentheses, 
write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"

Difficulty rating: Easy

Source:
http://www.leetcode.com/onlinejudge

Notes:
Use DP.
All valid parenthesis is of the form (x)y where x and y are valid parenthesis themselves.
*/

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) return vector<string>(1, "");
    if (n == 1) return vector<string>(1, "()");
    if (Cache.count(n)) return Cache[n];
    vector<string> result;
    for (int i = 0; i < n; ++i) {
      vector<string> a = generateParenthesis(i), b = generateParenthesis(n - 1 - i);
      for (int j = 0; j < a.size(); ++j) {
	for (int k = 0; k < b.size(); ++k) {
	  result.push_back("(" + a[j] + ")" + b[k]);
	}
      }
    }
    Cache[n] = result;
    return result;        
  }
private:
  map<int, vector<string> > Cache;
};
