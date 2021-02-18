#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    using PIII = pair<int, pair<int, int>>;
    int n = heightMap.size(), m = heightMap[0].size();
    vector<vector<bool>> st(n, vector<bool>(m, false));
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;

    for (int i = 0; i < n; i++) {
      st[i][0] = st[i][m - 1] = true;
      heap.push({heightMap[i][0], {i, 0}});
      heap.push({heightMap[i][m - 1], {i, m - 1}});
    }

    for (int j = 1; j < m - 1; j++) {
      st[0][j] = st[n - 1][j] = true;
      heap.push({heightMap[0][j], {0, j}});
      heap.push({heightMap[n - 1][j], {n - 1, j}});
    }

    int res = 0;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    while (heap.size()) {
      auto t = heap.top();
      heap.pop();

      for (int k = 0; k < 4; k++) {
        int x = t.second.first, y = t.second.second, h = t.first;
        int a = x + dx[k], b = y + dy[k];
        if (a >= 0 && a < n && b >= 0 && b < m) {
          if (st[a][b] == false) {
            st[a][b] = true;
            if (h > heightMap[a][b]) res += h - heightMap[a][b];
            heap.push({max(heightMap[a][b], h), {a, b}});
          }
        }
      }
    }

    return res;
  }
};

int main() {
  Solution sol;
  return 0;
}