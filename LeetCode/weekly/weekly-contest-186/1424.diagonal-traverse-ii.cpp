#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    map<int, vector<int>> mp;
    for (int i = nums.size() - 1; i >= 0; --i)
      for (int j = 0; j < nums[i].size(); ++j) mp[i + j].push_back(nums[i][j]);
    vector<int> ans;
    for (auto& t : mp)
      for (auto& u : t.second) ans.push_back(u);
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> ans = {1, 4, 2, 7, 5, 3, 8, 6, 9};
  auto ret = sol.findDiagonalOrder(nums);
  for (int i = 0; i < ret.size(); i++) {
    if (ret[i] != ans[i]) {
      cout << "fail" << endl;
    }
  }

  nums = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
  ans = {1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
  ret = sol.findDiagonalOrder(nums);
  for (int i = 0; i < ret.size(); i++) {
    if (ret[i] != ans[i]) {
      cout << "fail" << endl;
    }
  }

  nums = {{1, 2, 3}, {4}, {5, 6, 7}, {8}, {9, 10, 11}};
  ans = {1, 4, 2, 5, 3, 8, 6, 9, 7, 10, 11};
  ret = sol.findDiagonalOrder(nums);
  for (int i = 0; i < ret.size(); i++) {
    if (ret[i] != ans[i]) {
      cout << "fail" << endl;
    }
  }

  nums = {{1, 2, 3, 4, 5, 6}};
  ans = {1, 2, 3, 4, 5, 6};
  ret = sol.findDiagonalOrder(nums);
  for (int i = 0; i < ret.size(); i++) {
    if (ret[i] != ans[i]) {
      cout << "fail" << endl;
    }
  }

  return 0;
}