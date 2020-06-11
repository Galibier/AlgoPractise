#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    int len = s.size(), words_cnt = words.size();
    if (len == 0 or words_cnt == 0) return ans;

    unordered_map<string, int> dict;
    for (auto word : words) dict[word]++;

    int width = words[0].size();
    for (int i = 0; i < width; i++) {
      int left = i, count = 0;
      unordered_map<string, int> tdict;
      for (int j = i; j <= len - width; j += width) {
        auto str = s.substr(j, width);
        if (dict.count(str)) {
          tdict[str]++;
          if (tdict[str] <= dict[str])
            count++;
          else {
            while (tdict[str] > dict[str]) {
              auto str1 = s.substr(left, width);
              tdict[str1]--;
              if (tdict[str1] < dict[str1]) count--;
              left += width;
            }
          }
          if (count == words_cnt) {
            ans.push_back(left);
            tdict[s.substr(left, width)]--;
            count--;
            left += width;
          }
        } else {
          tdict.clear();
          count = 0;
          left = j + width;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};
  for (auto num : sol.findSubstring(s, words)) {
    cout << num << " ";
  }
  cout << endl;
  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "word"};
  for (auto num : sol.findSubstring(s, words)) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}