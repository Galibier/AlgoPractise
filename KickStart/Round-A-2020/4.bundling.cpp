#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TrieNode {
  int num;
  vector<TrieNode*> childs;
  TrieNode() {
    num = 0;
    childs.resize(26, nullptr);
  }
};

class TrieTree {
 public:
  TrieNode* root;
  int k;
  void insert(const string& str) {
    if (str.empty()) return;
    auto p = root;
    for (int i = 0; i < str.size(); ++i) {
      int cur = str[i] - 'A';
      if (p->childs[cur] == nullptr) {
        p->childs[cur] = new TrieNode();
      }
      p = p->childs[cur];
      p->num++;
    }
  }
  long long get_result() {
    long long result = 0;
    queue<TrieNode*> next;
    next.push(root);
    while (!next.empty()) {
      auto cur = next.front();
      next.pop();
      for (auto child : cur->childs) {
        if (child == nullptr || child->num < k) continue;
        result += child->num / k;
        next.push(child);
      }
    }
    return result;
  }
  TrieTree(int _k) {
    root = new TrieNode();
    k = _k;
  }
  ~TrieTree() {
    queue<TrieNode*> next;
    next.push(root);
    while (!next.empty()) {
      auto cur = next.front();
      next.pop();
      for (auto child : cur->childs) {
        if (child == nullptr) continue;
        next.push(child);
      }
      delete cur;
    }
  }
};
void slove() {
  long long n, k;
  cin >> n >> k;

  vector<string> strs(n);
  for (int i = 0; i < n; ++i) {
    cin >> strs[i];
  }
  TrieTree tree(k);
  for (auto str : strs) {
    tree.insert(str);
  }
  cout << tree.get_result() << endl;
}

int main() {
  int cases = 0;
  cin >> cases;
  for (int t = 0; t < cases; ++t) {
    long long n, k;
    cin >> n >> k;

    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
      cin >> strs[i];
    }
    TrieTree tree(k);
    for (auto str : strs) {
      tree.insert(str);
    }
    cout << "Case #" << t + 1 << ": " << tree.get_result() << endl;
  }
  return 0;
}