/*
Author: Timon Cui, timonbaby@163.com

Title: Container With Most Water

Description:
Given n non-negative integers a1, a2, ..., an, 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) 
and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.
Note: You may not slant the container.

Difficulty rating: Medium

Notes:

SolutionOn2:
Use sweep from left to right.
For current position, the only candidates to form a bigger bucket is 
the increasing subsequence from the first element in the list until now. 
So we only need to keep a list of increasing heights. 
Worse case complexity O(n^2). (For example, for 1, 2, 3, 4, ..., n).
Timeout for height = [1, 2, ..., 10000].

SolutionOnlogn:
Sweep from top to bottom. For each height, 
we keep track of current possible min and max bin. Complexity O(nlogn).
130 ms for 45 test cases in JudgeLarge.

Solution:
O(n). Start two pointers L and R from leftmost and rightmost and
move close to each other.
Each time, we move the shorter one to the next heigher value,
because this is the only way to increase capacity.
If two values are equal, we need to move both L and R.
90 ms for 45 test cases in JudgeLarge.

SolutionOnSimple:
One could simply L ++ if H[L] < H[R] and R -- otherwise.
Slightly less efficient but the logic is simpler.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int L = 0, R = height.size() - 1, max_area = 0;
        while (L < R) {
            max_area = max(max_area, (R - L) * min(height[L], height[R]));
            if (height[L] < height[R]) {
                int h = height[L];
                while (height[L] <= h) L ++;
            } else {
                int h = height[R];
                while (height[R] <= h) R --;
            }
        }
        return max_area;
    }
};

class SolutionOnSimple {
public:
    int maxArea(vector<int> &height) {
        int L = 0, R = height.size() - 1, max_area = 0;
        while (L < R) {
            max_area = max(max_area, (R - L) * min(height[L], height[R]));
            if (height[L] < height[R]) L ++;
	    else R --;
        }
        return max_area;
    }
};

class SolutionOnlogn {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2) return 0;

        vector<pair<int, int> > H;
        for (int i = 0; i < height.size(); ++i) {
            H.push_back(make_pair(i, height[i]));
        }
        sort(H.begin(), H.end(), compare);

        int mi = min(H[0].first, H[1].first);
        int ma = max(H[0].first, H[1].first);
        int res = min(H[0].second, H[1].second) * (ma - mi);
        for (int i = 2; i < H.size(); ++i) {
            mi = min(mi, H[i].first);
            ma = max(ma, H[i].first);
            res = max(res, H[i].second * (ma - mi));
        }
        return res;
    }
private:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class SolutionOn2 {
public:
    int maxArea(vector<int> &height) {
        vector<pair<int, int> > H;
        int ma = -1;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = 0; j < H.size(); ++j) {
                ma = max(ma, (i - H[j].first) * min(height[i], H[j].second));
            }
            if (H.empty() || height[i] > H.back().second) H.push_back(make_pair(i, height[i]));
        }
        return ma;       
    }
};
