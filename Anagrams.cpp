/*
Author: Timon Cui, timonbaby@163.com

Title: Anagrams

Description:
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

Difficulty rating: Easy

Notes: The problem statement can be clarified as: Output all strings who has an anagram in the array.

*/

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    typedef map<string, vector<string> > Groups;
    Groups groups;
    for (int i = 0; i < strs.size(); ++i) {
      string key = strs[i];
      sort(key.begin(), key.end());
      if (groups.count(key)) {
	groups[key].push_back(strs[i]);
      } else {
	groups[key] = vector<string>(1, strs[i]);
      }
    }
    vector<string> result;
    for (Groups::iterator i = groups.begin();
	 i != groups.end();
	 ++i) {
      if (i->second.size() > 1) {
	result.insert(result.end(), i->second.begin(), i->second.end());
      }
    }
    return result;
  }
};
