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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(), inorder.end());
        map<int, int> mp;
        for(int i = 0; i< inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        TreeNode *root = built(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
    TreeNode* built(vector<int>&preorder, int pstart, int pend, vector<int>&inorder, int istart, int iend, map<int, int>&mp){
        if(pstart>pend||istart>iend)return NULL;

        TreeNode * root = new TreeNode(preorder[pstart]);
        int indxroot=mp[root->val];
        int leftnum=indxroot-istart;

        root->left = built(preorder, pstart+1, pstart+leftnum, inorder, istart, indxroot-1, mp);
        root->right = built(preorder, pstart+leftnum+1, pend, inorder, indxroot+1, iend, mp);

        return root;
    }

};