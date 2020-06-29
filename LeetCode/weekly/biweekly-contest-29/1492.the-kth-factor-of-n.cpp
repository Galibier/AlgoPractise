#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int kthFactor(int n, int k) {
    for (int i = 1; i <= n; ++i) {
      if (n % i == 0) --k;
      if (k == 0) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}