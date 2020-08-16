#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool check(long long m, vector<int>& g, int num) {
    int Last = -1, cnt = 0;
    for (int i = 0; i < g.size(); i++) {
      if (Last == -1 || g[i] - g[Last] >= m) {
        cnt++;
        Last = i;
      }
    }
    return cnt >= num;
  }
  int maxDistance(vector<int>& g, int num) {
    sort(g.begin(), g.end());
    long long L = 0, R = 1e10, ans;
    while (L <= R) {
      long long m = L + (R - L + 1) / 2;
      if (check(m, g, num))
        ans = m, L = m + 1;
      else
        R = m - 1;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}