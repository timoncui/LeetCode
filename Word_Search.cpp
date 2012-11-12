/*
Author: Timon Cui, timonbaby@163.com

Title: Word Search

Description:
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Difficulty rating: Medium

Notes:

*/
            
class Solution {
public:
    bool exist(vector<vector<char> >& B, string word) {
        vector<vector<bool> > visited(B.size(), vector<bool>(B[0].size(), false));
        for (int i = 0; i < B.size(); ++i) {
            for (int j = 0; j < B[i].size(); ++j) {
                if (DFS(B, visited, i, j, word)) return true;
            }
        }
        return false;
    }
private:
    bool DFS(vector<vector<char> >& B, vector<vector<bool> >& visited, int i, int j, string word) {
        if (i < 0 || i >= B.size() || j < 0 || j > B[0].size()) return false;
        if (word.size() == 0) return true;
        if (visited[i][j] || word[0] != B[i][j]) return false;
        visited[i][j] = true;
        string s = word.substr(1, word.size());
        if (DFS(B, visited, i - 1, j, s) ||
            DFS(B, visited, i + 1, j, s) || 
            DFS(B, visited, i, j - 1, s) || 
            DFS(B, visited, i, j + 1, s)) {
            return true;
        } else {
            visited[i][j] = false;
            return false;
        }
    }
};
