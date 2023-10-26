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
    void makePostOrder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        makePostOrder(root->left,ans);
        makePostOrder(root->right,ans);
        ans.push_back(root->val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        makePostOrder(root,ans);
        return ans;
    }
};