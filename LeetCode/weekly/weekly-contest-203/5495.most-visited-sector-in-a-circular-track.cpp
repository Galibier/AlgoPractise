#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> mostVisited(int n, vector<int> &rounds) {
    int start = rounds[0], end = rounds[rounds.size() - 1];
    vector<int> ans;
    if (start <= end) {
      for (int i = start; i <= end; i++) {
        ans.push_back(i);
      }
    } else {
      for (int i = 1; i <= end; i++) {
        ans.push_back(i);
      }
      for (int i = start; i <= n; i++) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> vec{3, 2, 1, 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 1};
  for (auto c : sol.mostVisited(3, vec)) cout << c << endl;
  return 0;
}