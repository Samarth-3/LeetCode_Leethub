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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* end;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(root->val<prev->val){
            if(first==NULL){ //ki pehli discripency hai
                first=prev;
                mid=root;
            }
            else{ //2nd discrepency hogyi
                end=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=mid=end=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && end){ //means ki wrongs nodes val are not adjusent (aaj baaju nahi hai)
            swap(first->val,end->val);
        }
        else{ //measn ki adjusent hahi ie aaju baaju 
            swap(first->val,mid->val);
        }
    }
};