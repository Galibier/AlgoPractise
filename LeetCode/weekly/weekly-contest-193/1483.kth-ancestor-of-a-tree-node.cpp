#include <vector>
using namespace std;

class TreeAncestor {
 private:
  vector<vector<int>> dp;

 public:
  TreeAncestor(int n, vector<int>& parent) : dp(n) {
    for (int i = 0; i < n; i++) dp[i].push_back(parent[i]);

    for (int j = 1;; j++) {
      bool allneg = true;
      for (int i = 0; i < n; i++) {
        int t = dp[i][j - 1] != -1 ? dp[dp[i][j - 1]][j - 1] : -1;
        dp[i].push_back(t);
        if (t != -1) {
          allneg = false;
        }
      }
      if (allneg) {
        break;
      }
    }
  }

  int getKthAncestor(int node, int k) {
    if (k == 0 || node == -1) {
      return node;
    }
    int pos = ffs(k) - 1;
    return pos < dp[node].size() ? getKthAncestor(dp[node][pos], k - (1 << pos)) : -1;
  }
};

int main() {
  TreeAncestor treeAncestor = TreeAncestor(7, {-1, 0, 0, 1, 1, 2, 2});
  treeAncestor.getKthAncestor(3, 1);
  treeAncestor.getKthAncestor(5, 2);
  treeAncestor.getKthAncestor(6, 3);
  return 0;
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */