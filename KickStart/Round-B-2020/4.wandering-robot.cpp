#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
  vector<vector<int>> path(m, vector<int>(n, 1));
  for (int i = 2; i <= m; i++)
    for (int j = 2; j <= n; j++) path[i][j] = path[i - 1][j] + path[i][j - 1];
  return path[m][n];
}

int validPaths(int w, int h, int l, int u, int r, int d) {
  vector<vector<int>> path(w + 1, vector<int>(h + 1, 1));
  for (int i = 2; i <= w; i++)
    for (int j = 2; j <= h; j++) {
      if ((i >= l and i <= r) or (j >= u and j <= d))
        path[i][j] = 0;
      else
        path[i][j] = path[i - 1][j] + path[i][j - 1];
    }
  return path[w][h];
}

int main() {
  int cases;
  cin >> cases;
  for (int k = 0; k < cases; k++) {
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;

    int valid = validPaths(w, h, l, u, r, d);
    int all = uniquePaths(w, h);

    cout << "case #" << k + 1 << ": " << valid << "/" << all << endl;
  }

  return 0;
}