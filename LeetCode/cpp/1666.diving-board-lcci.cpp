#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> divingBoard(int shorter, int longer, int k) {
    if (k == 0) {
      return vector<int>{};
    }
    if (shorter == longer) {
      return vector<int>{shorter * k};
    }
    vector<int> vec(k + 1);
    for (int i = 0; i <= k; i++) {
      vec[i] = (k - i) * shorter + i * longer;
    }
    return vec;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}