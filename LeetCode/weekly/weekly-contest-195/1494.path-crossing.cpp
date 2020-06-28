#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
 public:
  bool isPathCrossing(string path) {
    set<pair<int, int>> st;
    st.emplace(make_pair(0, 0));
    int x = 0, y = 0;
    for (auto c : path) {
      if (c == 'N') y++;
      if (c == 'S') y--;
      if (c == 'W') x--;
      if (c == 'E') x++;
      auto point = make_pair(x, y);
      if (st.find(point) != st.end()) return true;
      st.emplace(point);
    }
    return false;
  }
};

int main() {
  Solution sol = Solution();
  string path = "NES";
  cout << sol.isPathCrossing(path) << endl;
  path = "NESWW";
  cout << sol.isPathCrossing(path) << endl;
  return 0;
}