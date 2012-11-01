/*
Author: Timon Cui, timonbaby@163.com

Title: Rotate Array

Description:
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Difficulty rating: Easy

Source:
http://www.cs.bell-labs.com/cm/cs/pearls/s02b.pdf
http://basicalgos.blogspot.com/2012/04/40-rotate-array-in-place.html

Notes:

*/

#include "utils.hpp"

template <class T>
void rotate1(std::vector<T>& x, const int N) {
  std::reverse(x.begin(), x.begin() + N);
  std::reverse(x.begin() + N, x.end());
  std::reverse(x.begin(), x.end());
}

template <class T>
void rotate2(std::vector<T>& x, int k) {
  int beg = 0, end = x.size(), mid = k;
  while (beg < mid) {
    std::swap(x[beg++], x[mid++]);
    if (mid == end) mid = k;
    else if (beg == k) k = mid;
  }      
}

int main( int argc, char* argv[] ) {
  const int N = 100;
  std::vector<int> a(N), b(N);
  std::vector<int> offsets(3);
  offsets[0] = 3;
  offsets[1] = 94;
  offsets[2] = 50;
  {
    for (int j = 0; j < (int)offsets.size(); ++j) {
      for (int i = 0; i < N; ++i) {
	a[i] = i;
	b[i] = (i + offsets[j]) % N;
      }
      rotate1(a, offsets[j]);
      eq(j, a, b);
    }
  }
  {
    for (int j = 0; j < (int)offsets.size(); ++j) {
      for (int i = 0; i < N; ++i) {
	a[i] = i;
	b[i] = (i + offsets[j]) % N;
      }
      rotate2(a, offsets[j]);
      eq(j, a, b);
    }
  }
}
