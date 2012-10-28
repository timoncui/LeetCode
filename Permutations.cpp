/*
Author: Timon Cui, timonbaby@163.com

Title: Permutations

Description:

Difficulty rating: Easy

Notes:

Solution:
For each permutation of num[1:], insert num[0] to all possible locations.

Solution2:
For each i, num[i] + permute(num[:i] + num[i + 1:]) is a valid permutation.

There are other solutions based on couting i from 0 to N!,
and consider i as a N - 1 digit number denoted as:
i = 0 * v0 + 1 * v_1 + 2 * v_2 + 6 * v_3 + 24 * v4 + ... + (N - 1)! * v_{N - 1}
where v_k = 0, ..., k denotes the index to choose for the (N - k)-th element
in the permutation.
This only works when N is small because the integer would overflow.

The best method is to use the next_permutation method to generate proper indices:
https://github.com/timoncui/LeetCode/blob/master/Next_Permutation.cpp

*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 1) return vector<vector<int> >(1, num);
        vector<int> rest(num.begin() + 1, num.end());
        vector<vector<int> > part = permute(rest);
        vector<vector<int> > result;
        for (int i = 0; i < part.size(); ++i) {
            for (int j = 0; j <= part[i].size(); ++j) {
                vector<int> p = part[i];
                p.insert(p.begin() + j, num[0]);
                result.push_back(p);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 1) return vector<vector<int> >(1, num);
        vector<vector<int> > result;
        for (int i = 0; i < num.size(); ++i) {
            vector<int> sub = num;
            sub.erase(sub.begin() + i);
            vector<vector<int> > p = permute(sub);
            for (int j = 0; j < p.size(); ++j) {
                p[j].push_back(num[i]);
                result.push_back(p[j]);
            }
        }
        return result;
    }
};