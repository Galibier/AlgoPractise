#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> vec;
    vec.push_back(make_pair(a, 'a'));
    vec.push_back(make_pair(b, 'b'));
    vec.push_back(make_pair(c, 'c'));
    string ans;
    while (vec[0].first or vec[1].first or vec[2].first) {
      sort(vec.begin(), vec.end());
      if (ans.empty() or ans.back() != vec[2].second) {
        if (vec[2].first-- > 0) ans = ans + vec[2].second;
        if (vec[2].first-- > 0) ans = ans + vec[2].second;
      } else {
        if (vec[1].first-- > 0)
          ans = ans + vec[1].second;
        else
          break;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.longestDiverseString(1, 1, 7) << endl;
  cout << sol.longestDiverseString(2, 2, 1) << endl;
  cout << sol.longestDiverseString(7, 1, 0) << endl;
  return 0;
}