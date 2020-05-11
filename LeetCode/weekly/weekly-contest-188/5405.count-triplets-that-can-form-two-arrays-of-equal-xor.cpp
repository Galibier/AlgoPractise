#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    vector<int> tmp(arr.size() + 1, 0);
    for (int i = 1; i <= arr.size(); i++) {
      tmp[i] = tmp[i - 1] ^ arr[i - 1];
    }
    for (auto i : tmp) {
      cout << i << " ";
    }
    cout << endl;
    int ans = 0;
    for (int i = 0; i < tmp.size() - 1; i++) {
      for (int j = i + 1; j < tmp.size(); j++) {
        if (tmp[i] == tmp[j]) {
          ans += (j - i - 1);
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> arr{2, 3, 1, 6, 7};
  cout << sol.countTriplets(arr) << endl;
  arr = {1, 1, 1, 1, 1};
  cout << sol.countTriplets(arr) << endl;
  arr = {2, 3};
  cout << sol.countTriplets(arr) << endl;
  arr = {1, 3, 5, 7, 9};
  cout << sol.countTriplets(arr) << endl;
  arr = {7, 11, 12, 9, 5, 2, 7, 17, 22};
  cout << sol.countTriplets(arr) << endl;
  return 0;
}