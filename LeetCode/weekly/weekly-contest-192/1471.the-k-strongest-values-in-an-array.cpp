#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int m = arr[(arr.size() - 1) / 2];
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      return abs(a - m) > abs(b - m) || abs(a - m) == abs(b - m) && a > b;
    });
    vector<int> ans(arr.begin(), arr.begin() + k);
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}