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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;
        int level= 0;
        q.push({root, level});
        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            if (temp.second >= ans.size()) {
                ans.push_back({temp.first->val});
            }
            else {
                ans[temp.second].push_back(temp.first->val);
            }
            level = temp.second + 1;
            if (temp.first->left) q.push({temp.first->left, level});
            if (temp.first->right) q.push({temp.first->right, level});
        }
        return ans;
    }
};