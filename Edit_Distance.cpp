/*
Author: Timon Cui, timonbaby@163.com

Title: Edit Distance

Description:
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Difficulty rating: Medium

Notes: An efficient implementation uses DP instead of recursion.
O(MN) where M and N are lengths of the two strings, respectively.

*/

class Solution {
public:
    int minDistance(string& word1, string& word2) {
        int N = word1.size(), M = word2.size();
        int H[N + 1][M + 1];        
        for (int i = 0; i <= N; ++i) H[i][0] = i;
        for (int i = 0; i <= M; ++i) H[0][i] = i;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (word1[i - 1] == word2[j - 1]) H[i][j] = H[i - 1][j - 1];
                else H[i][j] = 1 + min(min(H[i - 1][j - 1], H[i - 1][j]), H[i][j - 1]);
            }
        }
        return H[N][M];
    }
};
