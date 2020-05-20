#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    for (auto& entry : edges) {
      maps[entry[0]].push_back(entry[1]);
    }

    hasAppleHelper(0, hasApple);

    return maps.empty() ? 0 : 2 * (maps.size() - 1);
  }

 private:
  bool hasAppleHelper(int idx, vector<bool>& hasApple) {
    bool selfOrChildHasApple = hasApple[idx];
    for (auto i : maps[idx]) {
      selfOrChildHasApple = hasAppleHelper(i, hasApple) || selfOrChildHasApple;
    }
    if (!selfOrChildHasApple) {
      maps.erase(idx);
    }
    return selfOrChildHasApple;
  }

 private:
  unordered_map<int, vector<int>> maps;
};

int main() {
  Solution sol = Solution();
  return 0;
}