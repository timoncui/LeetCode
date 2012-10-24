/*
Author: Timon Cui, timonbaby@163.com

Title: Longest Valid Parentheses

Description:
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Difficulty rating: Hard

Notes:

Solution 1 (SolutionStack):

O(n) time and O(n) space.
With a stack, we keep track of the positions of all open left parentheses.
Each time a matching right parentheses appears, we pop the stack.
The longest valid string ending at current location
can extend to the left to: 
(a) position of the top of the stack + 1, if the stack is not empty.
For example, for s = "(()" when we get to i = 2.
or (b), min value of all previously matched left parentheses.
For example, for s = "()()" when we get to i = 3.
When the number of right parentheses exceeds the number of left,
we need to reset the counters and continue.

50 ms for 229 test cases in JudgeLarge.

Solution 2:

O(n) time and O(1) space.
Scan from left to right, keep track of # left and # right. 
When they equal, we reach the end of a valid string.
When # right exceeds # left, reset the counters and continue.
This fails for cases such as s = "(()", but scan again from right to left fixes it.
The correctness is a little hard to prove (see below).

35 ms for 229 test cases in JudgeLarge.

Correctness:
Denote the longest valid string as v. 
If v is a suffix or prefix of s, obviously the method can find it.
Otherwise, s can only be of two forms: 
...)v... or
...(v(...
For the first case, when we reach the ')' before v, # right must have exceeded # left,
otherwise v can be extened further to the left, violating the assumption that v is longest.
So v would be a fresh start.
For the second case, similar argument would show that scanning from the right would make v
a fresh start from the right.
*/

class Solution {
public:
  int longestValidParentheses(string s) {   
    int max_length = 0;
    int start[] = {0, s.length() - 1}, step[] = {1, -1}, end[] = {s.length(), -1}, ok_sign[] = {1, -1};
    for (int k = 0; k < 2; ++k) {
      int left = 0, right = 0;
      for (int i = start[k]; i != end[k]; i += step[k]) {
	if (s[i] == '(') left ++;
	else right ++;
	if (left == right) {
	  max_length = max(max_length, left + right);
	} else if (ok_sign[k] * (left - right) < 0) {
	  left = 0;
	  right = 0;
	}
      }
    }
    return max_length;
  }
};

class SolutionStack {
public:
  int longestValidParentheses(string s) {    
    stack<int> S;
    int max_length = 0, start = s.length();
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
	S.push(i);
      } else {
	if (S.empty()) {
	  start = s.length();
	} else {
	  start = min(start, S.top());
	  S.pop();
	  max_length = max(max_length, S.empty() ? i - start + 1 : i - S.top());
	}
      }
    }
    return max_length;
  }
};

