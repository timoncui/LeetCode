/*
Author: Timon Cui, timonbaby@163.com

Title: Valid Sudoku

Description:

Difficulty rating:

Notes: It's important to make the function distinct() efficient.
Further optimization is possible by returning false once res becomes false.

*/

class Solution {
public:
  bool distinct(const vector<char>& v) {
    vector<int> counter(9, 0);
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] != '.') {
	int index = v[i] - '1';
	if (counter[index]++ > 0) return false;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char> > &board) {
    bool res = true;
    vector<vector<char> > columns(9), squares(9);
    for (int i = 0; i < 9; ++i) {
      res &= distinct(board[i]);
      for (int j = 0; j < 9; ++j) {
	columns[j].push_back(board[i][j]);
	squares[i / 3 + j / 3 * 3].push_back(board[i][j]);
      }
    }
    for (int i = 0; i < 9; ++i) {
      res &= distinct(columns[i]);
      res &= distinct(squares[i]);
    }
    return res;
  }
};
