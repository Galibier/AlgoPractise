#include <vector>
using namespace std;

class Solution {
 public:
  bool visitRow[9][9] = {false};
  bool visitCol[9][9] = {false};
  bool visitBox[9][9] = {false};
  int num = 0;
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          visitRow[i][board[i][j] - '1'] = true;
          visitCol[j][board[i][j] - '1'] = true;
          visitBox[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
        }
      }
    }
    backTrack(board, 0, 0);
  }
  bool backTrack(vector<vector<char>>& board, int row, int col) {
    while (board[row][col] != '.') {
      if (++col >= 9) {
        col = 0;
        row++;
      }
      if (row >= 9) return true;
    }
    for (int i = 0; i < 9; i++) {
      int boxIndex = (row / 3) * 3 + col / 3;
      if (visitRow[row][i] || visitCol[col][i] || visitBox[boxIndex][i])
        continue;
      board[row][col] = i + '1';
      visitRow[row][i] = true;
      visitCol[col][i] = true;
      visitBox[boxIndex][i] = true;
      if (backTrack(board, row, col)) {
        return true;
      } else {
        board[row][col] = '.';
        visitRow[row][i] = false;
        visitCol[col][i] = false;
        visitBox[boxIndex][i] = false;
      }
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}