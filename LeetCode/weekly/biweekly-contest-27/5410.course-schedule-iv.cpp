#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<bool>> relation(n, vector<bool>(n, false));
    for (auto vec : prerequisites) {
      relation[vec[0]][vec[1]] = true;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          relation[i][j] = relation[i][j] || relation[i][k] && relation[k][j];
        }
      }
    }
    vector<bool> ans;
    for (auto vec : queries) {
      ans.push_back(relation[vec[0]][vec[1]]);
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}
