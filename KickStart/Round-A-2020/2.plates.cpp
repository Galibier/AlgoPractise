#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases = 0;
  cin >> cases;
  for (int t = 0; t < cases; ++t) {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> beaty(n, vector<int>(k, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        cin >> beaty[i][j];
      }
    }
    vector<vector<int>> sums(n, vector<int>(k + 1, 0));
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j < n; ++j) {
        sums[j][i] = sums[j][i - 1] + beaty[j][i - 1];
      }
    }
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= p; ++j) {
        dp[i][j] = INT_MIN;
        int max_per = min(j, k);
        for (int k = 0; k <= max_per; ++k) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + sums[i - 1][k]);
        }
      }
    }
    cout << "Case #" << t + 1 << ": " << dp[n][p] << endl;
  }
  return 0;
}