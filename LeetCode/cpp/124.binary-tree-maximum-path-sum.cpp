#include <algorithm>
#include <climits>
#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  int maxPathSum(TreeNode *root, int &val) {
    if (root == nullptr) return 0;
    int left = std::max(maxPathSum(root->left, val), 0);
    int right = std::max(maxPathSum(root->right, val), 0);

    int lmr = root->val + left + right;
    val = std::max(val, lmr);

    return root->val + std::max(left, right);
  }

 public:
  int maxPathSum(TreeNode *root) {
    int val = INT_MIN;
    maxPathSum(root, val);
    return val;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}