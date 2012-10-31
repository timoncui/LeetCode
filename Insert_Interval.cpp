/*
Author: Timon Cui, timonbaby@163.com

Title: Insert Interval

Description:
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Difficulty rating:

Source:
http://www.leetcode.com/onlinejudge

Notes:

[  ] [  ]  [    ]   [    ]   [       ]
     (  b  ] ib
                    (   e    ] ie

Binary search for b and e in the list.
remove everything between b and e
insert new interval = min(b, begin after b), max(e, end after e)


*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include "utils.hpp"
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int ib = lower_bound(intervals.begin(), intervals.end(), newInterval, compare) - intervals.begin();
    int ie = lower_bound(intervals.begin(), intervals.end(), Interval(newInterval.end, 0), compare) - intervals.begin();
    if (ib > 0 && newInterval.start <= intervals[ib - 1].end) {
      newInterval.start = intervals[ib - 1].start;
      ib --;
    }
    if (ie > 0) newInterval.end = max(newInterval.end, intervals[ie - 1].end);
    if (ie < intervals.size() && newInterval.end >= intervals[ie].start) {
      newInterval.end = intervals[ie].end;
      ie ++;
    }
    vector<Interval> result(intervals.begin(), intervals.begin() + ib);
    result.push_back(newInterval);
    result.insert(result.end(), intervals.begin() + ie, intervals.end());
    return result;
  }
private:
  static bool compare(const Interval& a, const Interval& b) { return a.start < b.start; }
};

void Print(const vector<Interval>& v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << "[" << v[i].start << ", " << v[i].end << "] ";
  }
  cout << endl;
}

int main() {
  Solution s;  
  
  // Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
  {
    int b[] = {1, 6};
    int e[] = {3, 9};
    vector<Interval> intervals;
    for (int i = 0; i < ARRAYSIZE(b); ++i) {
      intervals.push_back(Interval(b[i], e[i]));
    }
    Interval i(2, 5);
    Print(intervals);
    Print(s.insert(intervals, i));
  }

  {
    int b[] = {1};
    int e[] = {5};
    vector<Interval> intervals;
    for (int i = 0; i < ARRAYSIZE(b); ++i) {
      intervals.push_back(Interval(b[i], e[i]));
    }
    Interval i(2, 3);
    Print(intervals);
    Print(s.insert(intervals, i));
  }

  //  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
  {
    int b[] = {1, 3, 6, 8, 12};
    int e[] = {2, 5, 7, 10, 16};
    vector<Interval> intervals;
    for (int i = 0; i < ARRAYSIZE(b); ++i) {
      intervals.push_back(Interval(b[i], e[i]));
    }
    Interval i(4, 9);
    Print(intervals);
    Print(s.insert(intervals, i));
  }                
}                                                                                                                                                               
    
