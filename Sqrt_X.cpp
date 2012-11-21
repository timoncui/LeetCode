/*
Author: Timon Cui, timonbaby@163.com

Title: Sqrt X

Description:
Implement int sqrt(int x).

Compute and return the square root of x.

Difficulty rating:

Source:

Notes:

Newton's method:
y = r^2 - x = 0
r' = r - y/derivative(y, r) = r - (r^2 - x) / 2r = r / 2 + x / 2r

*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  int sqrt(int x) {
    if (x <= 0) return 0;
    double half_x = x / 2.0;
    double r = 0.5 + half_x;
    while (abs(r * r - x) > 1e-6) r = r / 2 + half_x / r;
    return floor(r);
  }
};

int main() {
  Solution s;
  eq(0, sqrt(1), 1);
  eq(1, sqrt(8192), 90);
  eq(2, sqrt(25), 5);
}
