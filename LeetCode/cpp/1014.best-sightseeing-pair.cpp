#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int ans = 0, mx = A[0] + 0;
    for (int j = 1; j < A.size(); ++j) {
      ans = max(ans, mx + A[j] - j);
      mx = max(mx, A[j] + j);
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> A{8, 1, 5, 2, 6};
  cout << sol.maxScoreSightseeingPair(A) << endl;
  return 0;
}