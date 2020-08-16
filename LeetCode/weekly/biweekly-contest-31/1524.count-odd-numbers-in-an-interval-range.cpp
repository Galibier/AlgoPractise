#include <iostream>
using namespace std;

class Solution {
 public:
  int countOdds(int l, int r) { return cnt(r) - cnt(l - 1); }

  int cnt(int x) {
    if (x < 1)
      return 0;
    else
      return (x + 1) / 2;
  }
};

int main() {
  Solution sol;
  return 0;
}