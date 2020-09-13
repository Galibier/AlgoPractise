/*
 * https://leetcode-cn.com/problems/2vYnGI/
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
    sort(drinks.begin(), drinks.end());
    int count = 0;
    for (int i = 0; i < staple.size(); i++) {
      count = (count + Search(drinks, x - staple[i])) % 1000000007;
    }
    return count;
  }
  int Search(const vector<int> &vec, int target) {
    int l = 0, r = vec.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (target < vec[mid]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;
  vector<int> staple{2, 1, 1};
  vector<int> drinks{8, 9, 5, 1};
  cout << sol.breakfastNumber(staple, drinks, 9) << endl;
  return 0;
}