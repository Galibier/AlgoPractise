#include <cmath>
#include <iostream>
using namespace std;

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int states = minutesToTest / minutesToDie + 1;
    return ceil(log(buckets) / log(states));
  }
};

int main() {
  Solution sol;
  return 0;
}