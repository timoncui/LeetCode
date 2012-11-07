/*
Author: Timon Cui, timonbaby@163.com

Title: Palindrome Number

Description:
Determine whether an integer is a palindrome. 
Do this without extra space.

Difficulty rating: Easy

Source:
http://www.leetcode.com/2012/01/palindrome-number.html
http://www.leetcode.com/onlinejudge

Notes:

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = 1;
        while (x / base > 10) base *= 10;
        while (x > 9) {
            if (x / base != x % 10) return false;
            x = (x % base) / 10;
            base /= 10;
        }
        return true;
    }
};
