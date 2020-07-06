#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int equal_diff = arr[1] - arr[0];
    int i = 0;
    while (i < (int)arr.size() - 1) {
      if ((arr[i + 1] - arr[i]) != equal_diff) return false;
      i++;
    }
    return true;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}