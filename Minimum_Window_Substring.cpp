/*
Author: Timon Cui, timonbaby@163.com

Title: Minimum Window Substring

Description:
Given a string S and a string T, find the minimum window in S which will 
contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Difficulty rating: Hard

Notes:
The basic idea is to calculate a histogram of letters in T, need,
then try to maintain (start, end) such that the histogram of the substring of S
between the two indices, found, is no smaller than need. 
The algorithm has two stages:

Stage I:
Start with (start, end) = (0, 0), keep moving end to the right until a valid string is found.
Move start to the right as far as possible, while maintaining validity.
Now we have found a potential candidate for the shortest valid string.

Stage II:
There are two methods for this stage with only subtle conceptual differences:
(a). Method suggested by stormrage on LeetCode:
http://www.leetcode.com/2010/11/finding-minimum-window-in-s-which.html
Move end by one letter to the right, and repeat step 2 above. Keep iterating until the end of S.
(b). Note that we can only advance start when end is advance 
to the first letter that is equal to S[start], so we can advance end by >= 1 steps.

Another small subtlty is how to handle letters in S that are not in T.
One can either (c) explictly ignore them, or (d) let them go through the normal
logic of the code, which will simplify the code with no much harm to performance.

SolutionStormrage below implements (a)(c), and Solution implements (b)(d).
Also in Solution, stage I and II are explicitly separated for ease of understanding,
whereas in SolutionStormrage, stage I happens before L reaches T.size(),
and stage II happens after that, and L will never be changed again.

The algorithm has O(n) complexity. 70 ms for 266 test cases in JudgeLarge.
*/

class Solution {
public:
  string minWindow(string S, string T) {
    vector<int> need(256, 0), found(256, 0);
    for (int i = 0; i < T.size(); ++i) need[T[i]]++;
    string result = "";
    int begin = 0, end = 0, min_length = INT_MAX, L = 0;

    // Advance end until a valid end point
    while (end < S.size()) {
      if (++found[S[end]] <= need[S[end]]) L ++;
      if (L == T.size()) break;
      end ++;
    }
    if (L < T.size()) return "";
    
    while (end < S.size()) {
      // Advance begin as long as valid
      while (need[S[begin]] == 0 || need[S[begin]] < found[S[begin]]) {
	found[S[begin]] --;
	begin ++;
      }
      int length = end - begin + 1;
      if (length < min_length) {
	min_length = length;
	result = S.substr(begin, length);
      }
      // Advance end to the next valid location
      do {
	end ++;
	found[S[end]] ++;
      } while (end < S.length() && S[end] != S[begin]);
    }
    return result;      
  }
};

class SolutionStormrage {
public:
  string minWindow(string S, string T) {
    vector<int> need(256, 0), found(256, 0);
    for (int i = 0; i < T.size(); ++i) need[T[i]]++;
    string result = "";
    for (int end = 0, begin = 0, L = 0, min_length = INT_MAX; end < S.size(); ++end) {
      char c = S[end];
      if (need[c] == 0) continue;
      found[c] ++;
      if (found[c] <= need[c]) L ++;
      if (L == T.size()) {
	while (need[S[begin]] == 0 || need[S[begin]] < found[S[begin]]) {
	  if (need[S[begin]]) found[S[begin]] --;
	  begin ++;
	}
	int length = end - begin + 1;
	if (length < min_length) {
	  min_length = length;
	  result = S.substr(begin, length);
	}	
      }
    }
    return result;
  }
};
