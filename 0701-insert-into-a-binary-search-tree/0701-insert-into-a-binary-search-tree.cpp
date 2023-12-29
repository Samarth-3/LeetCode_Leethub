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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp1=root;
        if(root==NULL){return new TreeNode(val);}
        while(true){
            if(val>temp1->val){
                if(temp1->right!=NULL){
                    temp1=temp1->right;
                }
                else{
                    temp1->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(temp1->left!=NULL){
                    temp1=temp1->left;
                }
                else{
                    temp1->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};