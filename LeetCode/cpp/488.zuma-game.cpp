#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*
 * https://leetcode-cn.com/problems/zuma-game/solution/488-by-ikaruga/
 */
class Solution {
 public:
  int findMinStep(string board, string hand) {
    cnt = hand.size();
    for (auto c : hand) {
      h[c - 'A']++;
    }

    dfs(board, 0);
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }

  void dfs(string board, int step) {
    shoot(board);

    if (board.empty()) {
      ans = min(ans, step);
    }
    if (step == cnt) return;
    if (step >= ans) return;

    set<pair<int, char>> ins;
    for (int i = 0; i < board.size(); i++) {
      int t = board[i] - 'A';
      if (i == 0 || board[i] != board[i - 1]) {
        if (h[t] != 0) {
          ins.insert({i, 'A' + t});
        }
      }
      if (i != 0 && board[i] == board[i - 1]) {
        for (int j = 0; j < h.size(); j++) {
          if (j == t || h[j] == 0) continue;
          ins.insert({i, 'A' + j});
        }
      }
    }

    for (auto item : ins) {
      h[item.second - 'A']--;
      board.insert(item.first, 1, item.second);
      dfs(board, step + 1);
      board.erase(item.first, 1);
      h[item.second - 'A']++;
    }
  }

  void shoot(string& board) {
    for (int i = 0; i < (int)board.size() - 2; i++) {
      int j = i + 1;
      while (j < board.size() && board[i] == board[j]) j++;
      if (j - i < 3) {
        i = j - 1;
        continue;
      }
      board.erase(i, j - i);
      shoot(board);
      break;
    }
  }

 private:
  int ans = numeric_limits<int>::max();
  int cnt = 0;
  vector<int> h = vector<int>(26, 0);
};

int main() {
  Solution sol;
  return 0;
}