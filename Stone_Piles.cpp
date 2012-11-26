/*
Author: Timon Cui, timonbaby@163.com

Title: Stone Piles

Description:
There are N piles of stones where the ith pile has xi stones in it. Alice and Bob play the following game:

a. Alice starts, and they alternate turns.
b. In a turn, a player can choose any one of the piles of stones and divide the stones in it into 
any number of unequal piles such that no two of the piles you create should have the same number of stones. 
For example, if there 8 stones in a pile, it can be divided into one of these set of piles: 
(1,2,5), (1,3,4), (1,7), (2,6) or (3,5). 
c. The player who cannot make a move (because all the remaining piles are indivisible) loses the game.
Given the starting set of piles, who wins the game assuming both players play optimally?

Difficulty rating: Hard

Source:
https://www.interviewstreet.com/challenges/dashboard/#problem/4e758bbb9e922

Notes:
http://www.math.ucla.edu/~tom/Game_Theory/comb.pdf

*/

#include "utils.hpp"
#include "algorithm.hpp"
using namespace std;
using namespace jcui::algorithm;

// Calculate Sprague-Grundy value using DP when a pile can be split into multiple piles
vector<int> sprague_grundy_multiple_piles(int N) {
  vector<int> v(N + 1, 0);
  for (int i = 3; i <= N; ++i) {
    vector<int> H(N, 0);
    vector<vector<int> > split = split_no_repeat(i, i - 1);
    for (int j = 0; j < split.size(); ++j) {
      int x = 0;
      for (int k = 0; k < split[j].size(); ++k) {
	x ^= v[split[j][k]];
      }
      H[x] = 1;
    }
    int j = 0;
    while (H[j]) j ++;
    v[i] = j;
  }
  return v;
}

// One can observe that sg(i) = i - 4 for i >= 9, so calculation can be faster
vector<int> sprague_grundy_multiple_piles_fast(int N) {
  int va[] = {0, 0, 0, 1, 0, 2, 3, 4, 0};
  vector<int> v(va, va + 9);
  for (int i = 9; i <= N; ++i) v.push_back(i - 4);
  return v;
}
  
int winner(const vector<int>& v) {
  int N = *max_element(v.begin(), v.end());
  vector<int> sg = sprague_grundy_multiple_piles_fast(N);
  int x = 0;
  for (int i = 0; i < v.size(); ++i) x ^= sg[v[i]];
  return x ? 0 : 1;
}

int main() {
  string names[2] = {"ALICE", "BOB"};
  int T = 0;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int j = 0; j < N; ++j) cin >> v[j];
    cout << names[winner(v)] << endl;
  }
}
