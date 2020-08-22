#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m < n) {
      m >>= 1;
      n >>= 1;
      ++shift;
    }
    return m << shift;
  }
};

int main() {
  Solution sol;
  return 0;
}