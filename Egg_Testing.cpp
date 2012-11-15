/*
Author: Timon Cui, timonbaby@163.com

Title: Egg Testing

Description:
Suppose that we wish to know which windows in a 36-story building are safe to drop eggs from, 
and which will cause the eggs to break on landing. We make a few assumptions:
An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If an egg breaks when dropped, then it would break if dropped from a higher window.
If an egg survives a fall then it would survive a shorter fall.

It is not ruled out that the first-floor windows break eggs, 
nor is it ruled out that the 36th-floor windows do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, 
the experiment can be carried out in only one way. Drop the egg from the first-floor window; 
if it survives, drop it from the second floor window. Continue upward until it breaks. 
In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. 
What is the least number of egg-droppings that is guaranteed to work in all cases?

Difficulty rating: Medium

Source:
http://archive.ite.journal.informs.org/Vol4No1/Sniedovich/index.php

Notes:

DP. Denote D[e][f] as the mininum number of drops to gurantee it works in the worst case, we have
D[e][f] = 1 + min_k max(D[e - 1][k - 1], D[e][f - k])
This is O(EF^2) if min_k is calculated naively.

Note that D[e - 1][k - 1] is non-decreasing as k, and D[e][f - k] is non-increasing as k,
we can get the min of the two using binary search.
Overal time complexity is O(EFlogF), and spatial complexity is O(F).

The special case for egg = 2, we observe the sequence for floor = 1, 2, ... is:
1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, ...
In general, D[2][f] = floor(sqrt(2f + 0.25) + 0.5)

Fix f, and as e goes to infinity, D[e][f] goes to log(f).

Reference:
http://archive.ite.journal.informs.org/Vol4No1/Sniedovich/index.php
*/

#include "algorithm.hpp"
#include "utils.hpp"
using namespace std;
using jcui::algorithm::min_max;

int minDrops(int egg, int floor) {
  vector<vector<int> > D(2, vector<int>(floor + 1, 0));
  for (int f = 1; f <= floor; ++f) D[0][f] = f;
  D[1][1] = 1;
  for (int e = 2; e <= egg; ++e) {
    int ej = e % 2, ei = !ej;
    for (int f = 2; f <= floor; ++f) {
      D[ei][f] = 1 + min_max(D[ej].begin(), 
			     D[ej].begin() + f - 1,
			     D[ei].rbegin() + floor - f + 1,
			     D[ei].rbegin() + floor,
			     0);
    }
  }  
  return D[!(egg % 2)][floor];
}

int main() {
  eq(0, minDrops(2, 100), 14);
  eq(1, minDrops(2, 10), 4);
  eq(2, minDrops(2, 11), 5);
  eq(3, minDrops(2, 400), 28);
  eq(4, minDrops(2, 990), 44);
  eq(5, minDrops(2, 1000), 45);
  eq(6, minDrops(2, 10000), (int)floor(sqrt(0.25 + 2 * 10000) + 0.5));
  eq(7, minDrops(100, 100), 7);
  eq(8, minDrops(100, 32), 6);
  eq(9, minDrops(2, 32), 8);
}
