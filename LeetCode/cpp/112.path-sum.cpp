#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    if (root->val == sum && !root->left && !root->right) return true;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}