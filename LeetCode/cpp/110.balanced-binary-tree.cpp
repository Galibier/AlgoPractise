#include <iostream>
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
  int height(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    } else {
      return max(height(root->left), height(root->right)) + 1;
    }
  }

  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    } else {
      return abs(height(root->left) - height(root->right)) <= 1 &&
             isBalanced(root->left) && isBalanced(root->right);
    }
  }
};

int main() {
  Solution sol;
  return 0;
}