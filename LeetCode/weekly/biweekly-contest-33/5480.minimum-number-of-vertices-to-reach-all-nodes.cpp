#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> indeg(n);
    for (const auto& e : edges) {
      ++indeg[e[1]];
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (!indeg[i]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}