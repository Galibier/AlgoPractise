#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int lmax = left.empty() ? 0 : *max_element(left.begin(), left.end());
    int rmin = right.empty() ? 0 : (n - *min_element(right.begin(), right.end()));
    return max(lmax, rmin);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}