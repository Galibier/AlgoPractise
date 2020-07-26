#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int d, ans;
  vector<int> dfs(TreeNode *node, int dep) {
    if (node->left == nullptr && node->right == nullptr) {
      return {dep};
    }
    vector<int> leftDepth, rightDepth;
    if (node->left != nullptr) {
      leftDepth = dfs(node->left, dep + 1);
    }
    if (node->right != nullptr) {
      rightDepth = dfs(node->right, dep + 1);
    }
    int n = leftDepth.size(), m = rightDepth.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (leftDepth[i] + rightDepth[j] - 2 * dep <= d) ans++;
      }
    }
    for (auto g : rightDepth) leftDepth.push_back(g);
    return leftDepth;
  }
  int countPairs(TreeNode *root, int distance) {
    ans = 0;
    d = distance;
    dfs(root, 0);
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}