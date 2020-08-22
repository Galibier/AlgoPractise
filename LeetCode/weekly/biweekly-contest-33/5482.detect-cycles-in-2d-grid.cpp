#include <iostream>
#include <vector>
using namespace std;

class Solution {
  const int col[4] = {-1, 1, 0, 0};
  const int row[4] = {0, 0, 1, -1};

 public:
  bool containsCycle(vector<vector<char>>& grid) {}
  bool dfs(char c, vector<vector<char>>& grid, int x, int y, int x_, int y_) {
    if (x == x_ && y == y_) {
      return true;
    }
    if (grid[x][y] != c) {
      return false;
    }
    for (int i = 0; i < 4; i++) {
      if (x + col[i] >= 0 && x + col[i] < grid[0].size() && y + row[i] >= 0 &&
          y + row[i] < grid.size()) {
        if (dfs()) }
    }
  }
};
class Solution {
 public:
  bool containsCycle(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (backtrack(board, board[i][j], 0, i, j, i, j)) {  // 从二维表格的每一个格子出发
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool backtrack(vector<vector<char>>& board, char c, int cnt, int x, int y, int x_,
                 int y_) {
    if (board[x][y] != c) {  // 当前位的字母不相等，此路不通
      return false;
    }
    if (x == x_ && y == y_ && cnt>=4) {
      return true;
    }
    char tmp = board[x][y];
    board[x][y] = 0;  // 避免该位重复使用
    if ((x > 0 && backtrack(board, c, cnt+1, x - 1, y, x_, y_)) ||
        (y > 0 && backtrack(board, c, cnt+1,x, y - 1, x_, y_)) ||
        (x < board.size() - 1 && backtrack(board, c, cnt+1,x + 1, y, x_, y_)) ||
        (y < board[0].size() - 1 && backtrack(board, c, cnt+1,x, y + 1, x_, y_))) {
      return true;
    }
    board[x][y] = tmp;  // 如果都不通，则回溯上一状态
    return false;
  }
};

int main() {
  Solution sol;
  return 0;
}