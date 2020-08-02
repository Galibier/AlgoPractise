#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    if (k >= arr.size())
      return *max_element(arr.begin(), arr.end());
    else {
      int cnt = 0;
      int curr = arr[0];
      int index = 1;
      while (cnt < k && index < arr.size()) {
        if (curr > arr[index]) {
          cnt++;
        } else {
          curr = arr[index];
          cnt = 1;
        }
        index++;
      }
      return curr;
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr{1, 25, 35, 42, 68, 70};
  int k = 1;
  cout << sol.getWinner(arr, k) << endl;
  return 0;
}