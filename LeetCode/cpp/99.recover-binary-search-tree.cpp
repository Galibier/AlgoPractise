/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 */

// @lc code=start
/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        inOrder(root);
        swap(first->val, second->val);
    }

private:
    void inOrder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);

        if (root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        prev = root;

        inOrder(root->right);
    }

    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
};
// @lc code=end
