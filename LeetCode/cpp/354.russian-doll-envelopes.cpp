#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    if (envelopes.size() == 0) {
      return 0;
    }
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
         });
    int n = envelopes.size(), res = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][1] < envelopes[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main() {
  Solution sol;
  return 0;
}