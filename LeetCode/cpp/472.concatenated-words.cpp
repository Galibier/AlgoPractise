#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node* children[26];
  bool isWord;
  Node() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    isWord = false;
  }
};

class Solution {
 public:
  Node* root;
  void insert(string& s) {
    Node* curr = root;
    for (int i = 0; i < s.length(); i++) {
      if (curr->children[s[i] - 'a'] == nullptr) {
        curr->children[s[i] - 'a'] = new Node();
      }
      curr = curr->children[s[i] - 'a'];
    }
    curr->isWord = true;
  }

  bool find(string& s, int p) {
    if (p == s.length()) return true;
    Node* curr = root;
    for (int i = p; i < s.length() && curr; i++) {
      curr = curr->children[s[i] - 'a'];
      if (curr && curr->isWord) {
        if (find(s, i + 1)) {
          return true;
        }
      }
    }
    return false;
  }
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    root = new Node();
    vector<string> ans;
    sort(words.begin(), words.end(), [](string& s1, string& s2) {
      if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
      }
      return s1 < s2;
    });
    for (int i = 0; i < words.size(); i++) {
      if (words[i].length() == 0) {
        continue;
      }
      if (find(words[i], 0)) {
        ans.emplace_back(words[i]);
      }
      insert(words[i]);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}