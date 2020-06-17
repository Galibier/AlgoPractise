#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* recoverFromPreorder(string str) {
    stack<TreeNode*> path;
    int pos = 0;
    while (pos < str.size()) {
      int level = 0;
      while (str[pos] == '-') {
        ++level;
        ++pos;
      }
      int value = 0;
      while (pos < str.size() && isdigit(str[pos])) {
        value = value * 10 + (str[pos] - '0');
        ++pos;
      }
      TreeNode* node = new TreeNode(value);
      if (level == path.size()) {
        if (!path.empty()) {
          path.top()->left = node;
        }
      } else {
        while (level != path.size()) {
          path.pop();
        }
        path.top()->right = node;
      }
      path.push(node);
    }
    while (path.size() > 1) {
      path.pop();
    }
    return path.top();
  }
};

int main() {
  Solution sol = Solution();
  sol.recoverFromPreorder("1-2--3--4-5--6--7");
  sol.recoverFromPreorder("1-2--3---4-5--6---7");
  sol.recoverFromPreorder("1-401--349---90--88");
  return 0;
}