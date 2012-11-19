/*
Author: Timon Cui, timonbaby@163.com

Title: Zombie March

Description:
 
Zombies have placed themselves at every junction in New York. Each junction 'i' initially has a presence of ai number of zombies. At every timestep each zombie randomly chooses one of its neighboring junctions and walks towards it. Each neighboring junction is choosen by the zombie with an equal probability. In order to safegaurd the citizens of New York we need to find out the number of zombies at every junction after 'k' timesteps.
 
The network of New York is given as an edge list. 
 
Input Format:
 
T-> 'T' test cases, T test cases follow.
 
N , M, k- > number of junctions(nodes) of New York, number of roads (edges) and 'k' time steps.
 
Followed by M lines containing m edges, 1 edge in each line. Each edge is denoted by 2 integers from 0 to N-1.  All the edges are bidirectional. Each node cannot connect itself.
 
Followed by N  lines having initial number of Zombies at the location ai.
 
 
Constraints:
 
1<=T<=5
5<=N<=100000
1<=M<= 200000
1<=k<=10000000
1<=ai<=1000
 
Output Format:
 
No of zombies (rounded of to its nearest integer)
in the Top 5 highly populated junctions after 'k' timesteps.

Difficulty rating:

Source:
https://www.interviewstreet.com/challenges/dashboard/#problem/4ff1484963063

Notes:

*/

#include "utils.hpp"
#include "algorithm.hpp"
using jcui::algorithm::SparseMat;
using jcui::algorithm::SparseMatCSR;
using namespace std;

vector<float> March(const SparseMatCSR<float>& G, const vector<float>& x, int k) {
  int p = 1;
  bool steady = false;
  vector<float> y = G * x;
  while (p < k && !steady) {
    p ++;
    vector<float> new_y = G * y;
    steady = true;
    for (int i = 0; i < y.size(); ++i) {
      if (fabs(y[i] - new_y[i]) > 1e-3f) {
	steady = false;
	break;
      }
    }
    y = new_y;
  }
  return y;
}

int main() {
  int T = 0;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int N, M, k;
    cin >> N >> M >> k;
    SparseMat<float> G(N, N);
    for (int i = 0; i < M; ++i) {
      int from, to;
      cin >> from >> to;
      G.set(from, to, 1.0f);
      G.set(to, from, 1.0f);
    }
    G.normalize_by_row_sum();
    vector<float> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];
    x = March(SparseMatCSR<float>(G), x, k);
    int output = min(5, N);
    partial_sort(x.begin(), x.begin() + output, x.end(), greater<float>());
    for (int i = 0; i < output; ++i) {
      cout << floor(0.5 + x[i]) << " ";
    }
    cout << endl;
  }
}
