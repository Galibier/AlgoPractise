class Solution {
 public:
  int stoneGameV(vector<int>& a) {
    int n = a.size();
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];

    const int INF = 1000000000;
    vector<vector<int>> f(n, vector<int>(n, -INF));
    for (int i = n - 1; i >= 0; --i) {
      f[i][i] = 0;
      for (int j = i + 1, p = i; j < n; ++j) {
        while (p + 1 < n && s[p + 2] - s[i] < s[j + 1] - s[p + 2]) {
          p += 1;
        }
        for (int k = max(i, p - 5); k <= min(p + 5, j - 1); ++k) {
          int ls = s[k + 1] - s[i], rs = s[j + 1] - s[k + 1];
          if (ls < rs)
            f[i][j] = max(f[i][j], f[i][k] + ls);
          else if (ls > rs)
            f[i][j] = max(f[i][j], f[k + 1][j] + rs);
          else {
            f[i][j] = max(f[i][j], max(f[i][k], f[k + 1][j]) + ls);
          }
        }
      }
    }
    return f[0][n - 1];
  }
};