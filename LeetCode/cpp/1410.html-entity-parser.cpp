#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 private:
  map<string, string> mp = {{"&quot;", "\""}, {"&apos;", "'"},
                            {"&amp;", "&"},   {"&gt;", ">"},
                            {"&lt;", "<"},    {"&frasl;", "/"}};

 public:
  string entityParser(string text) {
    string key;
    string res;
    for (auto achar : text) {
      if (achar == '&') {
        if (!key.empty()) {
          res += key;
          key.erase();
        }
        key.push_back(achar);
      } else if (achar != ';') {
        key.push_back(achar);
      } else {
        key.push_back(achar);
        if (mp.find(key) != mp.end()) {
          res += mp[key];
          key.erase();
        } else {
          res += key;
          key.erase();
        }
      }
    }
    if (!key.empty()) {
      res += key;
    }

    return res;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;
  cout << sol.entityParser("and I quote: &quot;...&quot;") << endl;
  cout << sol.entityParser("Stay home! Practice on Leetcode :)") << endl;
  cout << sol.entityParser("x &gt; y &amp;&amp; x &lt; y is always false") << endl;
  cout << sol.entityParser("leetcode.com&frasl;problemset&frasl;all") << endl;
  return 0;
}