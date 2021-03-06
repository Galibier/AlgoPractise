#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int ret = 0, sum = 0;
    for (auto n : nums) {
      sum += n;
      ret = max(ret, 1 - sum);
    }
    return ret > 0 ? ret : 1;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}