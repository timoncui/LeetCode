/*
Author: Timon Cui, timonbaby@163.com

Title: Maximal Rectangle

Description:

Difficulty rating: Hard

Notes:
Solution 1: For each pair of rows, calculate the max rect whose upper and lower
edges are these two rows, by taking and of all the rows in between and find the
longest run. O(n^3).

Several optimiazations can be performed to avoid unnecessary computation. (see code comments)
190 ms for 57 test cases in JudgeLarge.

Solution 2: For each row, calculate the max rect whose lower edge is the row
using the Largest_Rectangle_In_Histogram algorithm, which is O(n).
The overall complexity is O(n^2).

70 ms for 57 test cases in JudgeLarge.
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
    int maximalRectangle(vector<vector<char> > &matrix) {
        int H = matrix.size(), W = H ? matrix[0].size() : 0;
        if (H == 0) return 0;
        
        int max_rect = 0;
        vector<int> hist(W, 0);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                hist[j] = matrix[i][j] == '1' ? hist[j] + 1 : 0;
            }
            max_rect = max(max_rect, largestRectangleArea(hist));
        }
        return max_rect;
    }
};

class SolutionSlow {
public:
    vector<char> And(const vector<char>& a, const vector<char>& b) {
        vector<char> c(a.size(), '0');
        for (int i = 0; i < c.size(); ++i) {
            if (a[i] == '1' && b[i] == '1') c[i] = '1';
        }
        return c;
    }
    int maxRun(const vector<char>& v) {
        int current_run = 0, max_run = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == '1') {
                max_run = max(max_run, ++current_run);
            } else {
                current_run = 0;
            }
        }
        return max_run;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        int H = matrix.size(), W = H ? matrix[0].size() : 0;
        int max_rect = 0;
        for (int i = 0; i < H; ++i) {
            vector<char> all_ones(W, '1');
            for (int j = i; j < H; ++j) {
                all_ones = And(all_ones, matrix[j]);
                // Cannot exceed max_rect for this j
                if ((j - i + 1) * W <= max_rect) continue;
                int max_run = maxRun(all_ones);
                // Cannot exceed max_rect for the rest of j for this i
                if ((H - i) * max_run < max_rect) break;
                max_rect = max(max_rect, (j - i + 1) * max_run);
            }
        }
        return max_rect;
    }
};
