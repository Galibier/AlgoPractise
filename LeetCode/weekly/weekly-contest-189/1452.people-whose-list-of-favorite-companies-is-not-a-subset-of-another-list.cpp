#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    for (auto& f : favoriteCompanies) {
      sort(f.begin(), f.end());
    }

    map<int, vector<int>> mapSizeIndex;
    for (int i = 0; i < favoriteCompanies.size(); i++) {
      mapSizeIndex[favoriteCompanies[i].size()].push_back(i);
    }

    vector<int> ans;
    for (auto it = mapSizeIndex.rbegin(); it != mapSizeIndex.rend(); it++) {
      for (auto& p : it->second) {
        if (it != mapSizeIndex.rbegin() &&
            checkIncludes(favoriteCompanies, ans, p))
          continue;
        ans.push_back(p);
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }

  bool checkIncludes(vector<vector<string>>& fc, vector<int>& ans, int p) {
    for (auto i : ans) {
      if (includes(fc[i].begin(), fc[i].end(), fc[p].begin(), fc[p].end()))
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}