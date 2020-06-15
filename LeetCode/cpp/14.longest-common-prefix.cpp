#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    const auto p = minmax_element(
        strs.begin(), strs.end(),
        [](const string& str0, const string& str1) { return str0 < str1; });
    for (int i = 0; i < p.first->size(); ++i)
      if (p.first->at(i) != p.second->at(i)) return p.first->substr(0, i);
    return *p.first;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}