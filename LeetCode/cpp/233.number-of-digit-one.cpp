#include <cmath>
#include <iostream>
using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    if (n < 0) return 0;
    int ans = 0;
    int left, right = 0, idx = 0, cur = 0;
    while (n) {
      cur = n % 10;
      left = n / 10;
      if (cur == 0) {
        ans += left * pow(10, idx);
      } else if (cur == 1) {
        ans += left * pow(10, idx) + right + 1;
      } else {
        ans += (left + 1) * pow(10, idx);
      }
      right += cur * pow(10, idx);
      n /= 10;
      idx++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.countDigitOne(13) << endl;
  cout << sol.countDigitOne(12121) << endl;
  return 0;
}