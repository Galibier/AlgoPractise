#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> paths;
    vector<int> path;

    DFS(paths, path, nums, 0, 0, -101);

    return paths;
  }

  void DFS(vector<vector<int>> &paths, vector<int> &path, vector<int> nums,
           int loc, int len, int pre_num) {
    if (len >= 2) {
      paths.push_back(path);
    }

    unordered_map<int, int> map1;
    for (int i = loc; i < nums.size(); ++i) {
      if (nums[i] < pre_num || map1.find(nums[i]) != map1.end()) continue;
      map1[nums[i]] = 1;

      path.push_back(nums[i]);
      DFS(paths, path, nums, i + 1, len + 1, nums[i]);
      path.pop_back();
    }
  }
};

// DFS template
vector<vector<int>> findSubsequences(vector<int> &nums) {
  vector<vector<int>> paths;
  vector<int> path;

  DFS(paths, path, nums, 0);

  return paths;
}

void DFS(vector<vector<int>> &paths, vector<int> &path, vector<int> nums, int loc) {
  if (loc == nums.size()) {
    paths.push_back(path);
    return;
  }

  for (int i = loc; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    DFS(paths, path, nums, i + 1);
    path.pop_back();
  }
}

int main() {
  Solution sol;
  return 0;
}