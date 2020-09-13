/*
 * https://leetcode-cn.com/problems/UlBDOe/
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumOperations(string leaves) {
    int n = leaves.size();
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (leaves[i] == 'r' ? 1 : 0);
    }
    vector<int> mini(n + 1, 0);
    int currentMin = INT32_MAX;
    for (int i = 1; i < n - 1; i++) {
      currentMin = min(currentMin, i - 2 * sum[i]);
      mini[i] = currentMin;
    }
    int result = INT32_MAX;
    for (int j = n - 1; j > 1; j--)
      result = min(result, n - sum[n] + mini[j - 1] - j + 2 * sum[j]);
    return result;
  }
};

int main() {
  Solution sol;
  cout << sol.minimumOperations("rrryyyrryyyrr") << endl;
  return 0;
}