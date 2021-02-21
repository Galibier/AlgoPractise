#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
  static constexpr int base = 1337;

 public:
  int largestPalindrome(int n) {
    if (n == 1) return 9;
    int upper = pow(10, n) - 1;
    int lower = pow(10, n - 1);
    for (int i = upper; i >= lower; --i) {
      string temp = to_string(i);
      string pali = temp;
      reverse(pali.begin(), pali.end());
      long long product = stol(temp + pali);
      for (long long j = upper; j * j >= product; --j)
        if (product % j == 0) return product % base;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  return 0;
}