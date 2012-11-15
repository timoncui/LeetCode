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
}
