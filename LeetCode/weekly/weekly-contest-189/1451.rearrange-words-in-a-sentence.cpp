#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string arrangeWords(string text) {
    text[0] = tolower(text[0]);
    istringstream ww(text);
    string w;
    vector<string> words;
    while (ww >> w) {
      words.emplace_back(w);
    }
    vector<int> idx(words.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int& i, int& j) {
      return words[i].size() < words[j].size() ||
             ((words[i].size() == words[j].size()) && i < j);
    });
    string ans = "";
    for (auto i : idx) ans += words[i] + ' ';
    ans.pop_back();
    ans[0] = toupper(ans[0]);
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}