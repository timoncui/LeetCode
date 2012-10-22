/*
Author: Timon Cui, timonbaby@163.com

Title: Pow X N

Description:
Implement pow(x, n).

Difficulty rating: Easy

Notes: Note n can be negative.

*/

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double res = pow(x, abs(n) / 2);
        res *= res;
        if (n % 2 != 0) res *= x;
        return n < 0 ? 1 / res : res;
    }
};
