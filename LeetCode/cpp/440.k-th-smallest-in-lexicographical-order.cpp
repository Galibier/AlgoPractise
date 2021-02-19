#include <iostream>
using namespace std;

class Solution {
 public:
  long getCount(long prefix, long n) {
    long cur = prefix;
    long next = cur + 1;
    long count = 0;
    while (cur <= n) {
      count += min(n + 1, next) - cur;
      cur *= 10;
      next *= 10;
    }
    return count;
  }

  int findKthNumber(int n, int k) {
    long p = 1;
    long prefix = 1;
    while (p < k) {
      long count = getCount(prefix, n);
      if (p + count > k) {
        prefix *= 10;
        p++;
      } else if (p + count <= k) {
        prefix++;
        p += count;
      }
    }
    return static_cast<int>(prefix);
  }
};

int main() {
  Solution sol;
  return 0;
}