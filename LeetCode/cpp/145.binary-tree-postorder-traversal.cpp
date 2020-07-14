#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while (cur || stk.size()) {
      while (cur) {
        stk.push(cur);
        res.push_back(cur->val);
        cur = cur->right;
      }
      cur = stk.top();
      stk.pop();
      cur = cur->left;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution sol;
  sol.postorderTraversal(nullptr);
  return 0;
}