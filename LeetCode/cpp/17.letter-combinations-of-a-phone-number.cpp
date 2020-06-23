#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> ans;
  string tmp;
  string dic[10] = {"",    "",    "abc",  "def", "ghi",
                    "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return ans;
    tmp.resize(digits.size());
    dfs(digits, 0);
    return ans;
  }
  void dfs(string& digits, int k) {
    if (k == digits.size()) {
      ans.push_back(tmp);
      return;
    }
    int t = digits[k] - '0';
    for (int i = 0; i < dic[t].size(); i++) {
      tmp[k] = dic[t][i];
      dfs(digits, k + 1);
    }
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}