#include "algorithm.hpp"
#include "utils.hpp"
using namespace std;

int main() {
  { // Test lower_bound and min_max
  using jcui::algorithm::lower_bound;
  using jcui::algorithm::min_max;
  {
    int xa[] = {};
    int ya[] = {};
    vector<int> x(xa, xa + ARRAYSIZE(xa)), y(ya, ya + ARRAYSIZE(ya));
    int index = lower_bound(x.begin(), x.end(), y.begin(), y.end(), less<int>()) - x.begin();
    eq(0, index, 0);
    eq(0, min_max(x.begin(), x.end(), y.begin(), y.end(), 0), 0);
  }
  {
    int xa[] = {3, 4, 5, 6};
    int ya[] = {5, 4, 3, 1};
    vector<int> x(xa, xa + ARRAYSIZE(xa)), y(ya, ya + ARRAYSIZE(ya));
    int index = lower_bound(x.begin(), x.end(), y.begin(), y.end(), less<int>()) - x.begin();
    eq(1, index, 1);
    eq(1, min_max(x.begin(), x.end(), y.begin(), y.end(), 0), 4);
  }
  {
    int xa[] = {3, 3, 5, 6};
    int ya[] = {5, 4, 3, 1};
    vector<int> x(xa, xa + ARRAYSIZE(xa)), y(ya, ya + ARRAYSIZE(ya));
    int index = lower_bound(x.begin(), x.end(), y.begin(), y.end(), less<int>()) - x.begin();
    eq(2, index, 2);
    eq(2, min_max(x.begin(), x.end(), y.begin(), y.end(), 0), 4);
  }
  {
    int xa[] = {13, 14, 15, 16};
    int ya[] = {5, 4, 3, 1};
    vector<int> x(xa, xa + ARRAYSIZE(xa)), y(ya, ya + ARRAYSIZE(ya));
    int index = lower_bound(x.begin(), x.end(), y.begin(), y.end(), less<int>()) - x.begin();
    eq(3, index, 0);
    eq(3, min_max(x.begin(), x.end(), y.begin(), y.end(), 0), 13);
  }
  {
    int xa[] = {3, 4, 5, 6};
    int ya[] = {15, 14, 13, 11};
    vector<int> x(xa, xa + ARRAYSIZE(xa)), y(ya, ya + ARRAYSIZE(ya));
    int index = lower_bound(x.begin(), x.end(), y.begin(), y.end(), less<int>()) - x.begin();
    eq(4, index, 4);
    eq(4, min_max(x.begin(), x.end(), y.begin(), y.end(), 0), 11);
  }
  }
  
  { // For SparseMat
    using jcui::algorithm::SparseMat;
    {
      SparseMat<int> a(100, 100), b(100, 100);
      SparseMat<int> c = a * b;
      eq(c.get(3, 10), 0);
      eq(c.get(0, 0), 0);
    }
    {
      // a = [1, 2; 3, 0], b = [6, 0, 0; 0, 1, 4], a * b = [6, 2, 8; 18, 0, 0]
      SparseMat<int> a(100, 100), b(100, 100);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      b.set(0, 0, 6);
      b.set(1, 1, 1);
      b.set(1, 2, 4);
      SparseMat<int> c = a * b;
      eq(c.get(0, 0), 6);
      eq(c.get(0, 1), 2);
      eq(c.get(0, 2), 8);
      eq(c.get(1, 0), 18);
      eq(c.get(1, 1), 0);
      eq(c.get(1, 2), 0);
    }
    {
      // a = [1, 2; 3, 0]
      SparseMat<long> a(100, 100);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      SparseMat<long> c = pow(a, 17);
      eq(c.get(0, 0), 77431669L);
      eq(c.get(0, 1), 51708494L);
      eq(c.get(1, 0), 77562741L);
      eq(c.get(1, 1), 51577422L);
    }
    {
      // a = [1, 2; 3, 0]
      int N = 10;
      SparseMat<float> a(N, N);
      for (int i = 0; i < N; ++i) {
	a.set(i, i, 0.9f);
	a.set(i, (i + 1) % N, 0.05f);
	a.set(i, (i + N - 1) % N, 0.05f);
      }
      SparseMat<float> c = pow(a, 20000);
      for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	  eq(fabs(c.get(i, j) - 0.1f) < 1e-3f, true);
	}
      }
    }
    {
      // a = [1, 2; 3, 0]
      SparseMat<long> a(2, 2);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      long xa[] = {4, 5};
      vector<long> x(xa, xa + ARRAYSIZE(xa));
      vector<long> y = a * x;
      eq(y[0], 14L);
      eq(y[1], 12L);
    }
    {
      // a = [1, 2, 1; 3, 3, 0]
      SparseMat<int> a(2, 3);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(0, 2, 1);
      a.set(1, 0, 3);
      a.set(1, 1, 3);
      vector<int> y = SparseMat<int>::row_sum(a);
      eq(y[0], 4);
      eq(y[1], 5);
      eq(y[2], 1);
    }
    {
      // a = [1, 2, 1; 3, 3, 0]
      SparseMat<float> a(2, 3);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(0, 2, 1);
      a.set(1, 0, 3);
      a.set(1, 1, 3);
      a.normalize_by_row_sum();
      eq(a.get(0, 0), 0.25f);
      eq(a.get(0, 1), 0.4f);
      eq(a.get(0, 2), 1.0f);
      eq(a.get(1, 0), 0.75f);
      eq(a.get(1, 1), 0.6f);
      eq(a.get(1, 2), 0.0f);
    }
  }
  {
    using jcui::algorithm::RingBuffer;
    {
      RingBuffer<int> R(3);

      R.push_back(3);
      eq(R.get(0), 3);
      eq(R.get(-10), 0);
      eq(R.get(10), 0);
      eq(R.get(3), 0);
      
      R.push_back(2);
      eq(R.get(-1), 3);
      eq(R.get(0), 2);

      R.push_back(1);
      eq(R.get(-2), 3);
      eq(R.get(-1), 2);
      eq(R.get(0), 1);

      R.push_back(7);
      eq(R.get(-2), 2);
      eq(R.get(-1), 1);
      eq(R.get(0), 7);
      eq(R.get(-3), 0);
      eq(R.get(3), 0);
    }
  }
  {
    using jcui::algorithm::Mat;
    {
      // a = [1, 2; 3, 0], b = [6, 0, 0; 0, 1, 4], a * b = [6, 2, 8; 18, 0, 0]
      Mat<int> a(100, 100), b(100, 100);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      b.set(0, 0, 6);
      b.set(1, 1, 1);
      b.set(1, 2, 4);
      Mat<int> c = a * b;
      eq(c.get(0, 0), 6);
      eq(c.get(0, 1), 2);
      eq(c.get(0, 2), 8);
      eq(c.get(1, 0), 18);
      eq(c.get(1, 1), 0);
      eq(c.get(1, 2), 0);
    }
    {
      // a = [1, 2; 3, 0]
      Mat<long> a(100, 100);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      Mat<long> c = pow(a, 17);
      eq(c.get(0, 0), 77431669L);
      eq(c.get(0, 1), 51708494L);
      eq(c.get(1, 0), 77562741L);
      eq(c.get(1, 1), 51577422L);
      eq(c.get(10, 20), 0L);
    }
    {
      Mat<long> a(2, 2);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(1, 0, 3);
      long xa[] = {4, 5};
      vector<long> x(xa, xa + ARRAYSIZE(xa));
      vector<long> y = a * x;
      eq(y[0], 14L);
      eq(y[1], 12L);
    }
    {
      // a = [1, 2, 1; 3, 3, 0]
      Mat<float> a(2, 3);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(0, 2, 1);
      a.set(1, 0, 3);
      a.set(1, 1, 3);
      a.normalize_by_row_sum();
      eq(a.get(0, 0), 0.25f);
      eq(a.get(0, 1), 0.4f);
      eq(a.get(0, 2), 1.0f);
      eq(a.get(1, 0), 0.75f);
      eq(a.get(1, 1), 0.6f);
      eq(a.get(1, 2), 0.0f);
    }
  }
  {
    using jcui::algorithm::SparseMat;
    using jcui::algorithm::SparseMatCSR;
    {
      // a = [1, 2, 1; 3, 3, 0]
      SparseMat<int> a(2, 3);
      a.set(0, 0, 1);
      a.set(0, 1, 2);
      a.set(0, 2, 1);
      a.set(1, 0, 3);
      a.set(1, 1, 3);
      
      SparseMatCSR<int> b(a);

      int v[] = {1, 2, 1, 3, 3};
      eq(b.v, VI(v));
      int col[] = {0, 1, 2, 0, 1};
      eq(b.col, VI(col));
      int cum_n[] = {0, 3, 5};
      eq(b.cum_n, VI(cum_n));

      int c[] = {0, 5, 7};
      int res[] = {17, 15};
      eq(b * VI(c), VI(res));
    }
  }
  {
    using namespace jcui::algorithm;
    {
      vector<vector<int> > res = split_no_repeat(8, 7);
      eq((int)res.size(), 5);
    }
    {
      vector<vector<int> > res = split_no_repeat(10, 9);
      eq((int)res.size(), 9);
    }
  }
}
