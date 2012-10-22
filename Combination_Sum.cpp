/*
Author: Timon Cui, timonbaby@163.com

Title: Combination Sum

Description:
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

Difficulty rating: Medium

Notes: Equivalent to the Coin Change Problem. 
Assumption: Numbers in candidates are distinct.
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > results;
        if (candidates.empty()) return results;
        
        // Use last element
        int last = candidates.back();
        if (target == last) results.push_back(vector<int>(1, last));
        else if (target > last) {
            vector<vector<int> > rest = combinationSum(candidates, target - last);
            for (int i = 0; i < rest.size(); ++i) {
                rest[i].push_back(last);
                results.push_back(rest[i]);
            }
        }
        
        // Not use last element
        vector<int> candidates_leave_one(candidates.begin(), candidates.end() - 1);
        vector<vector<int> > rest = combinationSum(candidates_leave_one, target);
        results.insert(results.end(), rest.begin(), rest.end());
        return results;
    }
};