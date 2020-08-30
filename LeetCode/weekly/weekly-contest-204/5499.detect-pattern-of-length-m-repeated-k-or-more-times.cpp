#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int n) {
    if (m * n > arr.size()) {
      return false;
    }
    int len = m * n, size = arr.size();
    for (int i = 0; i <= size - len; i++) {
      bool flags = true;
      for (int k = 0; k < m; k++) {
        for (int j = 1; j < n; j++) {
          if (arr[i + k] != arr[m * j + i + k]) {
            flags = false;
          }
        }
      }
      if (flags) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> vec{1, 2, 4, 4, 4, 4};
  cout << sol.containsPattern(vec, 1, 3) << endl;
  vec = {1, 2, 1, 2, 1, 1, 1, 3};
  cout << sol.containsPattern(vec, 2, 2) << endl;
  vec = {1, 2, 1, 2, 1, 3};
  cout << sol.containsPattern(vec, 2, 3) << endl;
  vec = {1, 2, 3, 1, 2};
  cout << sol.containsPattern(vec, 2, 2) << endl;
  vec = {2, 2, 2, 2};
  cout << sol.containsPattern(vec, 2, 3) << endl;
  vec = {2, 2, 1, 2, 2, 1, 1, 1, 2, 1};
  cout << sol.containsPattern(vec, 2, 2) << endl;
  return 0;
}