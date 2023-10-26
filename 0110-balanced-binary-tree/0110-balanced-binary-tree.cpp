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
    int heightOfTree(TreeNode* root){
        if(root == NULL) return 0;
        int left = heightOfTree(root->left);
        int right = heightOfTree(root->right);

        return max(left,right)+1;
    }       
public:
    bool isBalanced(TreeNode* root) {
         if(root == NULL) return true;
         if(abs(heightOfTree(root->left)-heightOfTree(root->right)) > 1) return false;
         bool left = isBalanced(root->left);
         bool right = isBalanced(root->right);
         if(!left || !right) return false;
         else return true;
    }
};