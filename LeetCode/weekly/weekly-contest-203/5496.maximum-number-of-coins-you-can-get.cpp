#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end(), greater<int>());
    int cnt = piles.size() / 3;
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      ans += piles[i * 2 + 1];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}