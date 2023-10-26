/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int helper (TreeNode *root, int &ans) {
        if (!root) return -1;
        if (!root->left && !root->right) return 0;
        int lmax = 1 + helper(root->left, ans);
        int rmax = 1 + helper(root->right, ans);
        ans = max (ans, lmax+rmax);
        return max(lmax, rmax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int maxi = helper(root, ans);
        return ans;
    }
};