#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] % 2 == 1 && i + 2 < arr.size()) {
        if (arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> arr{2, 6, 4, 1};
  cout << sol.threeConsecutiveOdds(arr) << endl;
  vector<int> arr1{1, 2, 34, 3, 4, 5, 7, 23, 12};
  cout << sol.threeConsecutiveOdds(arr1) << endl;
  return 0;
}