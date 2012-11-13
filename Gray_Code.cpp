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

*/

#include "utils.hpp"
using namespace std;

/*
If we look at the k-th bit of the gray code sequence for 0, 1, 2, ... , the sequence goes like:
k = 0:
011001100..
k = 1:
001111000011110000...
k = 2:
0000111111110000000011111111...
In general, it's 2^k 0s followed by 2^{k + 1} 1s followed by 2^{k + 1} 0s ...
This means that the k-th bit for number n is:

  n + 2^k
 ---------- % 2
  2^{k + 1}

Visualize the logic below:

       +-------+------+
  ...  | k + 1 |  k   | ...
       +-------+------+

           ^      1
           |
           +    add 2^k

 divide by 2^{k + 1} then % 2 is this bit

So, G[k] = B[k] ^ B[k + 1], and BinaryToGray(n) =  (n >> 1) ^ n

To revert the process, B[k] = G[k] ^ B[k + 1].
We can solve from the largest k down to 0.
But if we realize that B[k] = G[k] ^ G[k + 1] ^ G[k + 2] + ..,
this can be solved more efficiently using a parallel prefix sum.

References:
Prefix sum: http://http.developer.nvidia.com/GPUGems3/gpugems3_ch39.html

*/

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> x(1 << n);
    for (int i = 0; i < x.size(); ++i) x[i] = BinaryToGray(i);
    return x;
  }
private:
  unsigned int BinaryToGray(unsigned int x) { return (x >> 1) ^ x; }
  unsigned int GrayToBinary(unsigned int x) {
    for (int i = 1; i < 8 * sizeof(unsigned int); i <<= 1) x ^= (x >> i);
    return x;
  }
};

/*

Alternate solution:

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

*/

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

/*
This problm can also be solved using recursive method below.
Not the most efficient one, but easy to derive.
*/

class Solution2 {
public:
  vector<int> grayCode(int n) {
    vector<int> x(1 << n);
    for (int i = 0; i < x.size(); ++i) {
      x[i] = atoi(GC(i, 8 * sizeof(int)));
    }
    return x;
  }
private:
  int atoi(string v) {
    int x = 0;
    for (int i = 0; i < v.size(); ++i) {
      x = (x << 1) + v[i] - '0';
    }
    return x;
  }
  string GC(int n, int len) {
    if (n == 0) return string(len, '0');
    int p = 1, k = 0;
    while (p <= n) {
      p <<= 1;
      k ++;
    }
    return string(len - k, '0') + "1" + GC((1 << k) - 1 - n, k - 1);
  }
};

int main() {
  Solution s;
  print(s.grayCode(4));
}
