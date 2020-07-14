#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> m;
    return helper(m, wordDict, s);
  }

 private:
  vector<string> helper(unordered_map<string, vector<string>>& m,
                        vector<string>& dict, string s) {
    if (m.count(s)) return m[s];
    if (s.empty()) return {""};
    vector<string> res;
    for (auto word : dict) {
      if (s.substr(0, word.size()) != word) continue;
      vector<string> tmp = helper(m, dict, s.substr(word.size()));
      for (auto item : tmp) {
        res.push_back(word + (item.empty() ? "" : " " + item));
      }
    }
    m[s] = res;
    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}