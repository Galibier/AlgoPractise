#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    vector<int> cnt(5, 0);
    int ret = -1;
    for (auto c : croakOfFrogs) {
      switch (c) {
        case 'c':
          cnt[0]++;
          break;
        case 'r':
          cnt[1]++;
          if (cnt[1] > cnt[0]) return -1;
          break;
        case 'o':
          cnt[2]++;
          if (cnt[2] > cnt[1]) return -1;
          break;
        case 'a':
          cnt[3]++;
          if (cnt[3] > cnt[2]) return -1;
          break;
        case 'k':
          cnt[4]++;
          ret = max(ret, cnt[0]);
          for (auto &n : cnt) n--;
          break;
        default:
          return -1;
      }
    }
    return cnt[0] == 0 ? ret : -1;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.minNumberOfFrogs("croakcroak") << endl;
  cout << sol.minNumberOfFrogs("crcoakroak") << endl;
  cout << sol.minNumberOfFrogs("croakcrook") << endl;
  cout << sol.minNumberOfFrogs("croakcroa") << endl;
  return 0;
}