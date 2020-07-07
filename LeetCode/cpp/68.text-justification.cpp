#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    string str;
    vector<int> index;
    for (int i = 0; i < words.size(); i++) {
      if (str.length() + words[i].length() < maxWidth) {
        str += words[i];
        index.push_back(str.length());
        str += ' ';
      } else if (str.length() + words[i].length() == maxWidth) {
        str += words[i];
        ret.push_back(str);
        str.clear();
        index.clear();
      } else {
        int gap = maxWidth - str.length();
        if (index.size() > 1) {
          str.erase(index.back(), 1);
          index.pop_back();
          gap++;
        }
        int x = 0, y = 0;
        if (!index.empty()) {
          x = gap / index.size();
          y = gap % index.size();
        }
        for (int j = index.size() - 1; j >= 0; j--) {
          str.insert(index[j], string(x + (j < y ? 1 : 0), ' '));
        }
        ret.push_back(str);
        str = words[i];
        index.clear();
        if (str.length() < maxWidth) {
          index.push_back(str.length());
          str += ' ';
        }
      }
    }
    if (!str.empty()) {
      if (str.length() < maxWidth) str += string(maxWidth - str.length(), ' ');
      ret.push_back(str);
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  vector<string> words{"Science", "is",        "what", "we",      "understand",
                       "well",    "enough",    "to",   "explain", "to",
                       "a",       "computer.", "Art",  "is",      "everything",
                       "else",    "we",        "do"};
  int maxWidth = 20;
  for (auto str : sol.fullJustify(words, maxWidth)) cout << str << endl;
  return 0;
}