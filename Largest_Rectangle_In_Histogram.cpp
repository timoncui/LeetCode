/*
Author: Timon Cui, timonbaby@163.com

Title: Largest Rectangle In Histogram

Description:
Given n non-negative integers representing 
the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Difficulty rating: Medium

Notes: O(n) time complexity. 80 ms for 94 tests in JudgeLarge.

Use a stack to keep track of open problems.
Reference: http://www.informatik.uni-ulm.de/acm/Locals/2003/html/judge.html
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int result = 0;
        stack<pair<int, int> > S;
        for (int i = 0; i < height.size(); ++i) {
            int h = height[i];
            int pos = i;
            while (!S.empty() && h < S.top().second) {
                pos = S.top().first;
                result = max(result , S.top().second * (i - pos));
                S.pop();
            }
            if (S.empty() || h > S.top().second) S.push(make_pair(pos, h));
        }
        while (!S.empty()) {
            result = max(result , S.top().second * ((int)height.size() - S.top().first));
            S.pop();
        }
        return result;
    }
};
