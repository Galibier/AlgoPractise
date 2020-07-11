#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size());
  }
  TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l >= r) return nullptr;
    int mid = l + r >> 1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = dfs(nums, l, mid);
    root->right = dfs(nums, mid + 1, r);
    return root;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}