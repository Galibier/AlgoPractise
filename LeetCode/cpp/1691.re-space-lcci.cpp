#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  static constexpr long long P = (1LL << 31) - 1;
  static constexpr long long BASE = 41;

  long long getHash(const string &s) {
    long long hashValue = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      hashValue = hashValue * BASE + s[i] - 'a' + 1;
      hashValue = hashValue % P;
    }
    return hashValue;
  }

  int respace(vector<string> &dictionary, string sentence) {
    unordered_set<long long> hashValues;
    for (const auto &word : dictionary) {
      hashValues.insert(getHash(word));
    }

    vector<int> f(sentence.size() + 1, sentence.size());

    f[0] = 0;
    for (int i = 1; i <= sentence.size(); ++i) {
      f[i] = f[i - 1] + 1;
      long long hashValue = 0;
      for (int j = i; j >= 1; --j) {
        int t = sentence[j - 1] - 'a' + 1;
        hashValue = hashValue * BASE + t;
        hashValue = hashValue % P;
        if (hashValues.find(hashValue) != hashValues.end()) {
          f[i] = min(f[i], f[j - 1]);
        }
      }
    }

    return f[sentence.size()];
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}