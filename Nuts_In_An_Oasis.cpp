/*
Author: Timon Cui, timonbaby@163.com

Title: Nuts in Oasis

Description:
A pile of nuts is in an oasis, across a desert from a town. 
The pile contains ‘N’ kg of nuts, and the town is ‘D’ kilometers away from the pile.

The goal of this problem is to write a program that will compute ‘X’, 
the maximum amount of nuts that can be transported to the town.

The nuts are transported by a horse drawn cart that is initially next to the pile of nuts. 
The cart can carry at most ‘C’ kilograms of nuts at any one time. 
The horse uses the nuts that it is carrying as fuel. 
It consumes ‘F’ kilograms of nuts per kilometer traveled 
regardless of how much weight it is carrying in the cart. 
The horse can load and unload the cart without using up any nuts.

Your program should have a function that takes as input 4 real numbers 
D,N,F,C and returns one real number: ‘X’

Difficulty rating: Hard

Source:
http://www.leetcode.com/2011/01/nuts-in-oasis-interview-question-from.html

Notes:
Since the consuming rate is constant, we need to mininize distance traveled.
The key is to set the first stop point at a location such that by the time
the horse gets all nuts there, N amount of nuts has been consumed so that
for the next stage, one fewer round trip is required.

       d1             d2

 +------------->+--------------->+------------------->
 <-------------+<---------------+
 +------------->+--------------->
 <-------------+
 +------------->

Start     1st checkpoint   2nd checkpoint        destination


  N - d1 * 5 * C will need 3 instead of 5 rounds

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  float maxNuts(float N, float D, float C, float F) {
    if (N <= C) return max(N - D * F, 0.0f);
    int nCarts = ceil(N / C);
    // Amount of nuts to be consumed so that we save one round trip
    float amount = N - (nCarts - 1) * C;
    int nTrips = nCarts * 2 - 1;
    float distance = amount / nTrips / F;
    if (distance >= D) return N - nTrips * D * F;
    return maxNuts(N - amount, D - distance, C, F);
  }
};

class SolutionLeetCode {
public:
  float maxNuts(float N, float D, float C, float F) {
    if (N <= C) {
      float nutsAtDestination = N - D*F;
      return (nutsAtDestination >= 0.0) ?
	nutsAtDestination :
	0.0;    // out of fuel!
    } 
    // # trips you would travel back and forth
    int numTrips = 2*(ceil(N/C) - 1) + 1;
    // how many nuts you consume per km
    float costPerKm = numTrips * F;
    // remaining weight of nuts after consumption
    float remainingNuts = C*(ceil(N/C) - 1.0);
    // this is the distance you are able to travel before you
    // reach ONE LESS round trip fetching nuts
    // derived from eq: N - costPerKm * traveled = remainingNuts
    float traveled = (N - remainingNuts) / costPerKm; 
    // we are able to travel greater (or equal) than the remaining
    // distance, so fetch the nuts right to the destination
    if (traveled >= D)
      return N - D*costPerKm; 
    // calculate recursively as we travel ONE less round trip now.
    return maxNuts(remainingNuts, D-traveled, C, F);
  }
};

int main() {
  Solution s;
  SolutionLeetCode sg;
  int x[][4] = {
    {100, 20, 50, 1},
    {105, 20, 50, 1},
    {100, 50, 50, 1},
    {50, 20, 50, 1},
    {40, 20, 50, 1},
    {100, 19, 49, 2},
    {300, 78, 2, 3},
    {200, 99, 40, 3.2}
  };
  for (int i = 0; i < ARRAYSIZE(x); ++i) {
    eq(i, s.maxNuts(x[i][0], x[i][1], x[i][2], x[i][3]), sg.maxNuts(x[i][0], x[i][1], x[i][2], x[i][3]));
  }  
}
