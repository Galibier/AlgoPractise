#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(int n) {
    int ans = 0;
    for (int i = n / 2; i < n; i++) {
      ans += (2 * i + 1 - n);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  for (int i = 1; i < 11; i++) {
    cout << sol.minOperations(i) << endl;
  }
  return 0;
}