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
