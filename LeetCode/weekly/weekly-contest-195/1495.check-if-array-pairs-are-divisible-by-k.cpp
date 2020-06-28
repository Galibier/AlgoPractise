#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> mod(k);
    for (int num : arr) mod[(num % k + k) % k]++;
    for (int i = 1; i < k; ++i)
      if (mod[i] != mod[k - i]) return false;
    return mod[0] % 2 == 0;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> arr{1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
  cout << sol.canArrange(arr, 5) << endl;
  return 0;
}