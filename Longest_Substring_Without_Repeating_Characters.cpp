/*
Author: Timon Cui, timonbaby@163.com

Title: Longest Substring Without Repeating Characters

Description:
Given a string, find the length of the longest substring 
without repeating characters. For example, 
the longest substring without repeating letters 
for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", 
with the length of 1.

Difficulty rating: Medium

Source:
http://www.leetcode.com/2011/05/longest-substring-without-repeating-characters.html
http://www.leetcode.com/onlinejudge

Notes:

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> exist(256, false);
        int left = 0, right = 0, max_length = 0;
        while (right < s.size()) {
            // Extend to the right as far as possible
            while (right < s.size() && exist[s[right]] == false) exist[s[right ++]] = true;
            max_length = max(max_length, right - left);
            // Move left forward to next possible start
            if (right < s.size()) {
               do { exist[s[left ++]] = false; } while (s[left - 1] != s[right]);
            }
        }
        return max_length;
    }
};
