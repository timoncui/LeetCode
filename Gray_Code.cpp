/*
Author: Timon Cui, timonbaby@163.com

Title: Gray Code

Description:
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Difficulty rating: Hard

Source:
http://www.leetcode.com/onlinejudge
http://en.wikipedia.org/wiki/Gray_code

Notes:

Note that 1 bit gray code goes:
0
1

For 2 bit, we append 0 in front, and:
00
01
now we have to flip the first bit, because otherwise the code wraps back, so next code is
11
now it's ok to keep going, flip the last bit
10

For 3 bit, it's similar:
000
001
011
010
now we have to flip first bit:
110
100
101
111

In general, for gray code of length L = k, the cycle is 2^k.
For i in [2^k, 2^{k + 1} - 1], the code C[-k:] = C[(i - 1) % 2^k][:k], and C[-(k+1)] = 1

This is equivalent to adding 2^k to previously found codes in a circular order.

The solution on OnlineJudge uses a similar logic, but instead of going on the loop using modulo,
it reverts the previously found code and prepends "1".
For example:
000
001
Reverse will give 001, 000
So what's followed are
101
100
Reverse the whole group gives 100, 101, 001, 000
So what's followed are
1100
1101
1001
1000

SolutionOnlineJudge implements this in order to pass the tests.

Complexity O(N) where N = 2^n. Amortized O(1) for each number generated.

Alternatively, if we look at the k-th bit for the gray code, the sequence goes like:
k = 0:
0110011001100..
k = 1:
001111000011110000...
k = 2:
00001111111100000000...
In general, it's 2^k 0 followed by 2^{k + 1} 1 followed by 2^{k + 1} 0 ...
This means that the k-th bit for number n is
(n + 2^k) / 2^{k + 1} % 2.

Visualize the logic below:
       +-------+------+
  ...  | k + 1 |  k   | ...
       +-------+------+

           ^      1
           |
           +    add 2^k

 divide by 2^{k + 1} then % 2 is this bit

The final result for the k-th bit is the XOR of the (k + 1)-th bit and the k-th bit.
In conclusion, gray_code(n) =  (n >> 1) ^ n.
*/

#include "utils.hpp"
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> x(1 << n);
    for (int i = 0; i < x.size(); ++i) {
      x[i] = (i >> 1) ^ i;
    }
    return x;
  }
};

class SolutionOnlineJudge {
public:
  vector<int> grayCode(int n) {
    vector<int> x(1 << n);
    for (int k = 0; k < n; ++k) {
      int len = 1 << k;
      for (int i = 0; i < len; ++i) {
	x[len + i] = len + x[len - 1 - i];
      }
    }
    return x;
  }
};

int main() {
  Solution s;
  print(s.grayCode(4));
}
