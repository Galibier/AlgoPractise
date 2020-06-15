#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    map<int, int> mp;
    for (auto num : arr) {
      mp[num]++;
    }
    vector<pair<int, int>> vec;
    for (auto m : mp) {
      vec.emplace_back(make_pair(m.first, m.second));
    }
    sort(vec.begin(), vec.end(),
         [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
           return lhs.second < rhs.second;
         });
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
      k -= vec[i].second;
      if (k >= 0) {
        cnt++;
      } else {
        break;
      }
    }
    return vec.size() - cnt;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> arr = {5, 5, 4};
  int k = 1;
  cout << sol.findLeastNumOfUniqueInts(arr, k) << endl;
  arr = {4, 3, 1, 1, 3, 3, 2};
  k = 3;
  cout << sol.findLeastNumOfUniqueInts(arr, k) << endl;
  return 0;
}