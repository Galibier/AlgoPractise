#include <iostream>
#include <vector>

class Solution {
 public:
  int climbStairs(int n) {
    int ssr[3] = {1, 2, 3};
    for (int i = 3; i < n; i++) {
      ssr[(i) % 3] = ssr[(i - 1) % 3] + ssr[(i - 2) % 3];
    }
    return ssr[(n - 1) % 3];
  }
};

int main() {
  Solution sol;
  return 0;
}