#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int ans = 0;
    istringstream words(sentence);
    string w;
    while (words >> w) {
      ++ans;
      w = string(w.begin(), w.begin() + searchWord.size());
      if (w == searchWord) return ans;
    }
    return -1;
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.isPrefixOfWord("i love eating burger", "burg") << endl;
  cout << sol.isPrefixOfWord("this problem is an easy problem", "pro") << endl;
  cout << sol.isPrefixOfWord("i am tired", "you") << endl;
  cout << sol.isPrefixOfWord("i use triple pillow", "pill") << endl;
  cout << sol.isPrefixOfWord("hello from the other side", "they") << endl;
  return 0;
}