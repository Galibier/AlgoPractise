/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    int len = s.size(), cnt = words.size();
    if (len == 0 or cnt == 0) return ans;

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
          if (count == cnt) {
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
// @lc code=end
