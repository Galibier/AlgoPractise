#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  double average(vector<int>& ss) {
    int maxs = numeric_limits<int>::min(), mins = numeric_limits<int>::max();
    int sums = 0;
    for (int& s : ss) {
      sums += s;
      maxs = max(maxs, s);
      mins = min(mins, s);
    }
    return static_cast<double>(sums - maxs - mins) / (ss.size() - 2);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}