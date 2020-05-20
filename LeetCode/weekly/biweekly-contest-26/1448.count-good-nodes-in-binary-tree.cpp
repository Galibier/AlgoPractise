
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
  int goodNodes(TreeNode *root) {
    int res = 0;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int curmx) {
      if (!node) {
        return;
      }

      if (node->val >= curmx) {
        curmx = node->val;
        ++res;
      }

      dfs(node->left, curmx);
      dfs(node->right, curmx);
    };

    dfs(root, -1e6);

    return res;
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}
