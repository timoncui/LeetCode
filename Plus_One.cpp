/*
Author: Timon Cui, timonbaby@163.com

Title: Plus One

Description:
Given a number represented as an array of digits, plus one to the number.

Difficulty rating: Easy

Notes:

*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, N = digits.size(), pos = N - 1;
        while (carry && pos >= 0) {
            carry += digits[pos];
            digits[pos] = carry % 10;
            carry /= 10;
            pos --;
        }
        if (carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};
