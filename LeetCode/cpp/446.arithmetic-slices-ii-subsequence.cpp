#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    long long ans = 0;
    vector<map<long long, int>> cnt(n);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        long long delta = (long long)A[i] - (long long)A[j];
        int sum = 0;
        if (cnt[j].find(delta) != cnt[j].end()) {
          sum = cnt[j][delta];
        }
        cnt[i][delta] += sum + 1;
        ans += sum;
      }
    }

    return (int)ans;
  }
};

int main() {
  Solution sol;
  return 0;
}