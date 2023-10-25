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
         TreeNode* root=new TreeNode(preorder[0]);
         TreeNode* tempRoot = root;
         for(int i=1; i<preorder.size(); i++){
             TreeNode* temp = new TreeNode(preorder[i]);
             root = tempRoot;
             while(root != NULL){
                if(temp->val < root->val){ 
                    {
                        if(root->left == NULL){
                            root->left = temp;
                            break;
                        }
                    }      
                    root = root->left;
                }
                else if(temp->val > root->val){ 
                    {
                        if(root->right == NULL){
                            root->right = temp;
                            break;
                        }
                    }      
                    root = root->right;
                }
             }
             
         }
         return tempRoot;

    }
};