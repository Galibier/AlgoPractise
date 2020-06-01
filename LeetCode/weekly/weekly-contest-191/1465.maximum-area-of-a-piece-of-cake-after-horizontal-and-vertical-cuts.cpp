#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());
    int high = max(horizontal[0], h - horizontal[horizontal.size() - 1]);
    int width = max(vertical[0], w - vertical[vertical.size() - 1]);

    for (int i = 1; i < horizontal.size(); i++) {
      high = max(horizontal[i] - horizontal[i - 1], high);
    }
    for (int i = 1; i < vertical.size(); i++) {
      width = max(vertical[i] - vertical[i - 1], width);
    }
    return int64_t(high) * int64_t(width) % 1000000007;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}