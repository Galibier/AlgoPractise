#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (int i = 0; i < words.size(); ++i)
      for (int j = 0; j < words.size(); ++j) {
        if (i == j) continue;
        if (words[j].find(words[i]) != string::npos) {
          ans.push_back(words[i]);
          break;
        }
      }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<string> words1 = {"mass", "as", "hero", "superhero"};
  for (auto str : sol.stringMatching(words1)) cout << str << " ";
  cout << endl;
  vector<string> words2 = {"leetcode", "et", "code"};
  for (auto str : sol.stringMatching(words2)) cout << str << " ";
  cout << endl;
  vector<string> words3 = {"blue", "green", "bu"};
  for (auto str : sol.stringMatching(words3)) cout << str << " ";
  cout << endl;
  return 0;
}