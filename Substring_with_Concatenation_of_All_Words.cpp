/*
Author: Timon Cui, timonbaby@163.com

Title: Substring with Concatenation of All Words

Description:

Difficulty rating: Medium

Notes:

Brute force solution tries all substrings of S of proper length,
split it into L.size() sub strings, and check if they are the same set as L.
This is O(SLN), and takes 1550 ms for 160 test cases in JudgeLarge.

A better solution uses a sliding window, similar to the 
"Shortest substring of A containing all characters in B" problem.
This is O(SN), and taks 160 ms for 160 test cases in JudgeLarge.

*/

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    int N = L[0].size();
    if (N * L.size() > S.size()) return result;        
    map<string, int> need;
    for (int i = 0; i < L.size(); ++i) need[L[i]] ++;
        
    for (int i = 0; i < N; ++i) {
      map<string, int> found;
      // Try to find a valid region
      int begin = i, pos = i, valid_elements = 0;
      while (pos < S.size()) {
	string s = S.substr(pos, N);
	if (need.count(s) == 0) {
	  pos += N;
	  begin = pos;
	  valid_elements = 0;
	  found.clear();
	} else {
	  found[s] ++;
	  if (found[s] <= need[s]) valid_elements ++;
	  if (valid_elements == L.size()) break;
	  pos += N;
	}
      }
      if (valid_elements < L.size()) continue;
      while (pos < S.size()) {
	// Try move begin to the right as much as possible
	string s = S.substr(begin, N);
	while (need[s] < found[s]) {
	  found[s] --;
	  begin += N;
	  s = S.substr(begin, N);
	}
	if (pos - begin == N * (L.size() - 1)) result.push_back(begin);
	// Next valid	
	string t = "";
	do {
	  pos += N;
	  if (pos < S.size()) t = S.substr(pos, N);
	  found[t] ++;
	} while (t != s && pos < S.size());
      }
    }
    return result;
  }
};

class SolutionBruteForce {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    int N = L[0].size();
    if (N * L.size() > S.size()) return result;
    map<string, int> need;
    for (int i = 0; i < L.size(); ++i) need[L[i]] ++;
    for (int i = 0; i <= S.size() - N * L.size(); ++i) {
      map<string, int> found;
      int j = 0;
      for (; j < L.size(); ++j) {
	string s = S.substr(i + j * N, N);
	if (need.count(s) == 0 || ++found[s] > need[s]) break;
      }
      if (j == L.size()) result.push_back(i);
    }
    return result;
  }
};
